#include "opencv_modules.h"

#ifdef HAVE_OPENCV_CALIB3D

#include "calib3dConstants.h"

using namespace cv;

void Calib3dConstants::Init(v8::Local<v8::Object> target) {
	FF_SET_JS_PROP(target, REGULAR, Nan::New<v8::Integer>(0));
	FF_SET_CV_CONSTANT(target, LMEDS);
	FF_SET_CV_CONSTANT(target, RANSAC);
	FF_SET_CV_CONSTANT(target, RHO);

	FF_SET_CV_CONSTANT(target, SOLVEPNP_ITERATIVE);
	FF_SET_CV_CONSTANT(target, SOLVEPNP_EPNP);
	FF_SET_CV_CONSTANT(target, SOLVEPNP_P3P);
	FF_SET_CV_CONSTANT(target, SOLVEPNP_DLS);
	FF_SET_CV_CONSTANT(target, SOLVEPNP_UPNP);

	FF_SET_CV_CONSTANT(target, CALIB_CB_ADAPTIVE_THRESH);
	FF_SET_CV_CONSTANT(target, CALIB_CB_NORMALIZE_IMAGE);
	FF_SET_CV_CONSTANT(target, CALIB_CB_FILTER_QUADS);
	FF_SET_CV_CONSTANT(target, CALIB_CB_FAST_CHECK);

	FF_SET_CV_CONSTANT(target, CALIB_CB_SYMMETRIC_GRID);
	FF_SET_CV_CONSTANT(target, CALIB_CB_ASYMMETRIC_GRID);
	FF_SET_CV_CONSTANT(target, CALIB_CB_CLUSTERING);

	FF_SET_CV_CONSTANT(target, CALIB_USE_INTRINSIC_GUESS);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_ASPECT_RATIO);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_PRINCIPAL_POINT);
	FF_SET_CV_CONSTANT(target, CALIB_ZERO_TANGENT_DIST);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_FOCAL_LENGTH);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_K1);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_K2);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_K3);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_K4);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_K5);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_K6);
	FF_SET_CV_CONSTANT(target, CALIB_RATIONAL_MODEL);
	FF_SET_CV_CONSTANT(target, CALIB_THIN_PRISM_MODEL);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_S1_S2_S3_S4);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_INTRINSIC);
	FF_SET_CV_CONSTANT(target, CALIB_SAME_FOCAL_LENGTH);
	FF_SET_CV_CONSTANT(target, CALIB_ZERO_DISPARITY);
#if CV_VERSION_GREATER_EQUAL(3, 1, 0)
	FF_SET_CV_CONSTANT(target, CALIB_TILTED_MODEL);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_TAUX_TAUY);
	FF_SET_CV_CONSTANT(target, CALIB_USE_LU);
#endif
#if CV_VERSION_GREATER_EQUAL(3, 2, 0)
	FF_SET_CV_CONSTANT(target, CALIB_USE_QR);
#endif
#if CV_VERSION_GREATER_EQUAL(3, 3, 0)
	FF_SET_CV_CONSTANT(target, SOLVEPNP_AP3P);
	FF_SET_CV_CONSTANT(target, SOLVEPNP_MAX_COUNT);
	FF_SET_CV_CONSTANT(target, CALIB_FIX_TANGENT_DIST);
#endif
	FF_SET_CV_CONSTANT(target, FM_7POINT);
	FF_SET_CV_CONSTANT(target, FM_8POINT);
	FF_SET_CV_CONSTANT(target, FM_LMEDS);
	FF_SET_CV_CONSTANT(target, FM_RANSAC);
}

#endif
