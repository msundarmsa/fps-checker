const checkFPSBtn = document.getElementById('checkFPSBtn');
const currDeviceInput = document.getElementById('currDeviceInput');
const currFrameworkInput = document.getElementById('currFrameworkInput');
const currFPSLbl = document.getElementById('currFPSLbl');

checkFPSBtn.onclick = e => {
    if (checkFPSBtn.innerText == 'Stop') {
        // stop checking
        checkFPSBtn.classList.remove('is-danger');
        checkFPSBtn.innerText = 'Check FPS';

        window.electronAPI.stopCamera();
    } else {
        // start checking
        checkFPSBtn.classList.add('is-danger');
        checkFPSBtn.innerText = 'Stop';

        window.electronAPI.startCamera(currDeviceInput.value, currFrameworkInput.value);
    }
};

window.electronAPI.handleUpdateFPS((event, fps) => {
    currFPSLbl.innerText = `Current FPS: ${fps.toFixed(2)}`;
});
