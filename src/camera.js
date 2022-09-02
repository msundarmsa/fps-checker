const cv = require("opencv-bindings");

let video = null;

function updateFPS(fps) {
    process.send({ cmd: 'FPS', fps: fps });
}

function isNumeric(str) {
    if (typeof str != "string") return false // we only process strings!
    return !isNaN(str) && // use type coercion to parse the _entirety_ of the string (`parseFloat` alone does not do this)...
           !isNaN(parseFloat(str)) // ...and ensure strings of whitespace fail
}

process.on('message', (msg) => {
    if (msg.cmd == "START_CAMERA") {
        let device = msg.device;
        if (isNumeric(device)) {
            device = parseInt(device);
        }
        startCamera(device, msg.framework);
    } else if (msg.cmd == "STOP_CAMERA") {
        video.release();
    }
});

const startCamera = (device, framework) => {
    let fmwk = null;
    if (framework == 'MSMF') {
        fmwk = cv.CAP_MSMF;
    } else if (framework == 'FFMPEG') {
        fmwk = cv.CAP_FFMPEG;
    } else if (framework == 'AVFoundation') {
        fmwk = cv.CAP_AVFOUNDATION;
    } else if (framework == 'DSHOW') {
        fmwk = cv.CAP_DSHOW;   
    } else {
        fmwk = cv.CAP_ANY;
    }
    console.log(`Framework: ${fmwk}`);
    video = new cv.VideoCapture(device, fmwk);

    let numFrames = 0;
    let startTime = 0;

    (function loop() {
        setTimeout(function () {
            if (!video) {
                // video closed
                return;
            }

            // grab frame and process
            if (grabFrame(video.read())) {
                // recurse only if grab frame was a success
                loop();

                numFrames = numFrames + 1;
                if (numFrames == 1) {
                    startTime = Date.now();
                }

                if (numFrames % 10 == 0) {
                    // every 10 frames update fps
                    const fps = numFrames / (Date.now() - startTime) * 1000;
                    updateFPS(fps);
                }
            }
        }, 1);
    })();
}

const grabFrame = (frame) => {
    return !frame.empty;
}