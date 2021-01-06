#ifdef ZIMG_X86_AVX512

#include <algorithm>
#include <cfloat>
#include <cmath>
#include "gamma_constants_avx512.h"

namespace zimg {
namespace colorspace {
namespace avx512constants {

const float Rec1886EOTF::horner[6] = {
	3.9435861748560828e-3f,
	-4.7562005414496558e-2f,
	3.7223934327652687e-1f,
	8.0976688115998239e-1f,
	-1.6576549352714846e-1f,
	2.7378258372778144e-2f,
};

const float Rec1886EOTF::table alignas(64)[16] = {
	0.00000000e+00f, // [-inf, -14)
	7.68054690e-11f, // [-14, -13)
	4.05381696e-10f, // [-13, -12)
	2.13961742e-09f, // [-12, -11)
	1.12929684e-08f, // [-11, -10)
	5.96046448e-08f, // [-10, -9)
	3.14595201e-07f, // [-9, -8)
	1.66044343e-06f, // [-8, -7)
	8.76387295e-06f, // [-7, -6)
	4.62559987e-05f, // [-6, -5)
	2.44140625e-04f, // [-5, -4)
	1.28858194e-03f, // [-4, -3)
	6.80117628e-03f, // [-3, -2)
	3.58968236e-02f, // [-2, -1)
	1.89464571e-01f, // [-1, 0)
	1.00000000e+00f, // [0, 1)
};

const float Rec1886InverseEOTF::horner[6] = {
	5.3331316297790816e-3f,
	-5.0653335401261418e-2f,
	2.0631810268332693e-1f,
	-4.8846483066245743e-1f,
	9.5048057786988787e-1f,
	3.7698771958831039e-1f,
};

const float Rec1886InverseEOTF::table alignas(64)[32] = {
	0.00000000e+00f, // [-inf, -30)
	1.72633492e-04f, // [-30, -29)
	2.30438065e-04f, // [-29, -28)
	3.07597913e-04f, // [-28, -27)
	4.10593953e-04f, // [-27, -26)
	5.48077172e-04f, // [-26, -25)
	7.31595252e-04f, // [-25, -24)
	9.76562500e-04f, // [-24, -23)
	1.30355455e-03f, // [-23, -22)
	1.74003656e-03f, // [-22, -21)
	2.32267015e-03f, // [-21, -20)
	3.10039268e-03f, // [-20, -19)
	4.13852771e-03f, // [-19, -18)
	5.52427173e-03f, // [-18, -17)
	7.37401807e-03f, // [-17, -16)
	9.84313320e-03f, // [-16, -15)
	1.31390065e-02f, // [-15, -14)
	1.75384695e-02f, // [-14, -13)
	2.34110481e-02f, // [-13, -12)
	3.12500000e-02f, // [-12, -11)
	4.17137454e-02f, // [-11, -10)
	5.56811699e-02f, // [-10, -9)
	7.43254447e-02f, // [-9, -8)
	9.92125657e-02f, // [-8, -7)
	1.32432887e-01f, // [-7, -6)
	1.76776695e-01f, // [-6, -5)
	2.35968578e-01f, // [-5, -4)
	3.14980262e-01f, // [-4, -3)
	4.20448208e-01f, // [-3, -2)
	5.61231024e-01f, // [-2, -1)
	7.49153538e-01f, // [-1, 0)
	1.00000000e+00f, // [0, 1)
};

const float ST2084EOTF::horner0 alignas(64)[32] = {
	2.3783206e-1f, 5.3487723e-2f, 6.9725438e-2f, 9.2311500e-2f, // [0, 3]
	1.2176837e-1f, 1.6016700e-1f, 2.1029731e-1f, 2.7583897e-1f, // [4, 7]
	3.6165950e-1f, 4.7422258e-1f, 6.2214308e-1f, 8.1694541e-1f, // [8, 11]
	1.0741050e+0f, 1.4144856e+0f, 1.8663342e+0f, 2.4680621e+0f, // [12, 15]
	3.2721476e+0f, 4.3506393e+0f, 5.8029690e+0f, 7.7671092e+0f, // [16, 19]
	1.0435617e+1f, 1.4078866e+1f, 1.9078925e+1f, 2.5979369e+1f, // [20, 23]
	3.5559070e+1f, 4.8942502e+1f, 6.7766052e+1f, 9.4431226e+1f, // [24, 27]
	1.3249397e+2f, 1.8726969e+2f, 2.6678396e+2f, 3.8328445e+2f, // [28, 31]
};

const float ST2084EOTF::horner1 alignas(64)[32] = {
	-4.4913414e-3f, +1.0114087e-2f, +6.0346995e-3f, -2.4363002e-3f, // [0, 3]
	-1.7180403e-2f, -4.1212870e-2f, -7.8865726e-2f, -1.3629793e-1f, // [4, 7]
	-2.2223892e-1f, -3.4904270e-1f, -5.3418094e-1f, -8.0236306e-1f, // [8, 11]
	-1.1885557e+0f, -1.7422975e+0f, -2.5338891e+0f, -3.6633069e+0f, // [12, 15]
	-5.2731001e+0f, -7.5671345e+0f, -1.0837977e+1f, -1.5507119e+1f, // [16, 19]
	-2.2184402e+1f, -3.1756357e+1f, -4.5518394e+1f, -6.5373990e+1f, // [20, 23]
	-9.4137073e+1f, -1.3599470e+2f, -1.9722094e+2f, -2.8728825e+2f, // [24, 27]
	-4.2061406e+2f, -6.1933324e+2f, -9.1774668e+2f, -1.3695407e+3f, // [28, 31]
};

const float ST2084EOTF::horner2 alignas(64)[32] = {
	2.0212520e-3f, 1.6286117e-3f, 2.0177877e-3f, 3.2161629e-3f, // [0, 3]
	5.9926554e-3f, 1.1644820e-2f, 2.2265499e-2f, 4.1157759e-2f, // [4, 7]
	7.3456985e-2f, 1.2705851e-1f, 2.1399855e-1f, 3.5250895e-1f, // [8, 11]
	5.7007568e-1f, 9.0799574e-1f, 1.4281776e+0f, 2.2233112e+0f, // [12, 15]
	3.4321180e+0f, 5.2622903e+0f, 8.0251232e+0f, 1.2188015e+1f, // [16, 19]
	1.8454418e+1f, 2.7886218e+1f, 4.2092088e+1f, 6.3519144e+1f, // [20, 23]
	9.5907509e+1f, 1.4500381e+2f, 2.1968960e+2f, 3.3378077e+2f, // [24, 27]
	5.0892188e+2f, 7.7928620e+2f, 1.1992847e+3f, 1.8563487e+3f, // [28, 31]
};

const float ST2084EOTF::horner3 alignas(64)[32] = {
	+2.8802992e-6f, +6.7830084e-6f, -9.9130278e-6f, -8.5689092e-5f, // [0, 3]
	-3.1881062e-4f, -9.1083514e-4f, -2.2441828e-3f, -5.0091196e-3f, // [4, 7]
	-1.0408578e-2f, -2.0485210e-2f, -3.8639718e-2f, -7.0447779e-2f, // [8, 11]
	-1.2494241e-1f, -2.1662153e-1f, -3.6858557e-1f, -6.1743835e-1f, // [12, 15]
	-1.0209430e+0f, -1.6699941e+0f, -2.7073699e+0f, -4.3571745e+0f, // [16, 19]
	-6.9712028e+0f, -1.1102217e+1f, -1.7620252e+1f, -2.7898091e+1f, // [20, 23]
	-4.4108683e+1f, -6.9704922e+1f, -1.1019876e+2f, -1.7443571e+2f, // [24, 27]
	-2.7669622e+2f, -4.4019065e+2f, -7.0292656e+2f, -1.1276591e+3f, // [28, 31]
};

const float ST2084EOTF::horner4 alignas(64)[32] = {
	-5.0238915e-10f, -9.0804149e-9f, 2.6239238e-7f, 2.0689909e-6f, // [0, 3]
	9.4319669e-6f, 3.2732739e-5f, 9.5593041e-5f, 2.4749664e-4f, // [4, 7]
	5.8625125e-4f, 1.2970695e-3f, 2.7194061e-3f, 5.4597617e-3f, // [8, 11]
	1.0580125e-2f, 1.9910299e-2f, 3.6562491e-2f, 6.5775423e-2f, // [12, 15]
	1.1629487e-1f, 2.0262735e-1f, 3.4871640e-1f, 5.9394040e-1f, // [16, 19]
	1.0029083e+0f, 1.6814878e+0f, 2.8031002e+0f, 4.6520049e+0f, // [20, 23]
	7.6948422e+0f, 1.2699455e+1f, 2.0933328e+1f, 3.4497073e+1f, // [24, 27]
	5.6888793e+1f, 9.3966622e+1f, 1.5560442e+2f, 2.5856660e+2f, // [28, 31]
};

const float ST2084InverseEOTF::horner0 alignas(64)[32] = {
	-5.3291990e+31f, -4.9636966e+30f, -4.6744578e+29f, -4.4440474e+28f, // [-31, -28]
	-4.2564252e+27f, -4.0962061e+26f, -3.9483972e+25f, -3.7986599e+24f, // [-27, -24]
	-3.6340745e+23f, -3.4442666e+22f, -3.2226262e+21f, -2.9672666e+20f, // [-23, -20]
	-2.6813858e+19f, -2.3728264e+18f, -2.0528481e+17f, -1.7343533e+16f, // [-19, -16]
	-1.4299546e+15f, -1.1502979e+14f, -9.0294352e+12f, -6.9193377e+11f, // [-15, -12]
	-5.1798908e+10f, -3.7914932e+09f, -2.7162926e+08f, -1.9068000e+07f, // [-11, -8]
	-1.3131320e+06f, -8.8820221e+04f, -5.9080378e+03f, -3.8692231e+02f, // [-7, -4]
	-2.4978198e+01f, -1.5912720e+00f, -1.0014762e-01f, +0.0000000e+00f, // [-3, -1], [-inf, -32]
};

const float ST2084InverseEOTF::horner1 alignas(64)[32] = {
	2.0778199e+23f, 3.8779456e+22f, 7.3158438e+21f, 1.3927997e+21f, // [-31, -28]
	2.6700881e+20f, 5.1402799e+19f, 9.9055033e+18f, 1.9039381e+18f, // [-27, -24]
	3.6366940e+17f, 6.8777810e+16f, 1.2834677e+16f, 2.3560451e+15f, // [-23, -20]
	4.2433922e+14f, 7.4828341e+13f, 1.2899211e+13f, 2.1714239e+12f, // [-19, -16]
	3.5674101e+11f, 5.7188683e+10f, 8.9472837e+09f, 1.3667830e+09f, // [-15, -12]
	2.0400518e+08f, 2.9778425e+07f, 4.2552561e+06f, 5.9593420e+05f, // [-11, -8]
	8.1889810e+04f, 1.1054594e+04f, 1.4677798e+03f, 1.9191152e+02f, // [-7, -4]
	2.4738095e+01f, 3.1473208e+00f, 3.9562847e-01f, 0.0000000e+00f, // [-3, -1], [-inf, -32]
};

const float ST2084InverseEOTF::horner2 alignas(64)[32] = {
	-3.6182830e+14f, -1.3562076e+14f, -5.1342627e+13f, -1.9594699e+13f, // [-31, -28]
	-7.5206876e+12f, -2.8944898e+12f, -1.1133995e+12f, -4.2654176e+11f, // [-27, -24]
	-1.6216078e+11f, -6.0967403e+10f, -2.2595850e+10f, -8.2322344e+09f, // [-23, -20]
	-2.9413229e+09f, -1.0287146e+09f, -3.5170566e+08f, -1.1743700e+08f, // [-19, -16]
	-3.8279558e+07f, -1.2179389e+07f, -3.7834009e+06f, -1.1480397e+06f, // [-15, -12]
	-3.4053613e+05f, -9.8829994e+04f, -2.8091528e+04f, -7.8289236e+03f, // [-11, -8]
	-2.1417595e+03f, -5.7582930e+02f, -1.5232960e+02f, -3.9696108e+01f, // [-7, -4]
	-1.0201794e+01f, -2.5884726e+00f, -6.4908363e-01f, +0.0000000e+00f, // [-3, -1], [-inf, -32]
};

const float ST2084InverseEOTF::horner3 alignas(64)[32] = {
	5.6219037e+5f, 4.2446802e+5f, 3.2177944e+5f, 2.4436862e+5f, // [-31, -28]
	1.8546077e+5f, 1.4030397e+5f, 1.0552708e+5f, 7.8704829e+4f, // [-27, -24]
	5.8060887e+4f, 4.2264527e+4f, 3.0292491e+4f, 2.1336892e+4f, // [-23, -20]
	1.4745721e+4f, 9.9857873e+3f, 6.6201545e+3f, 4.2939277e+3f, // [-19, -16]
	2.7240151e+3f, 1.6901489e+3f, 1.0258996e+3f, 6.0946484e+2f, // [-15, -12]
	3.5459750e+2f, 2.0221293e+2f, 1.1312541e+2f, 6.2146394e+1f, // [-11, -8]
	3.3560261e+1f, 1.7834018e+1f, 9.3357909e+0f, 4.8193675e+0f, // [-7, -4]
	2.4559205e+0f, 1.2366792e+0f, 6.1593215e-1f, 0.0000000e+0f, // [-3, -1], [-inf, -32]
};

const float ST2084InverseEOTF::horner4 alignas(64)[32] = {
	7.6889213e-5f, 1.0911610e-4f, 1.5720569e-4f, 2.2975174e-4f, // [-31, -28]
	3.4021635e-4f, 5.0963129e-4f, 7.7062198e-4f, 1.1732008e-3f, // [-27, -24]
	1.7927541e-3f, 2.7404741e-3f, 4.1760881e-3f, 6.3220782e-3f, // [-23, -20]
	9.4777109e-3f, 1.4030268e-2f, 2.0460181e-2f, 2.9336665e-2f, // [-19, -16]
	4.1301151e-2f, 5.7037462e-2f, 7.7229959e-2f, 1.0251331e-1f, // [-15, -12]
	1.3341952e-1f, 1.7032894e-1f, 2.1343140e-1f, 2.6270256e-1f, // [-11, -8]
	3.1789786e-1f, 3.7856411e-1f, 4.4406635e-1f, 5.1362617e-1f, // [-7, -4]
	5.8636643e-1f, 6.6135799e-1f, 7.3766392e-1f, 0.0000000e+0f, // [-3, -1], [-inf, -32]
};


// Debug implementations.
namespace {

template <class T>
float frexp_1_2(T x, int *exp)
{
	if (x == static_cast<T>(0.0)) {
		*exp = 0;
		return x;
	}

	x = std::frexp(x, exp);
	x *= static_cast<T>(2.0);
	*exp -= 1;
	return x;
}

template <class T>
float power_function(float x)
{
	const float input_max = std::nextafterf(2.0f, -INFINITY);
	constexpr int exponent_min = -static_cast<int>(sizeof(T::table) / sizeof(T::table[0]) - 1);

	float orig, mant, mantpart, exppart;
	int exp;

	orig = x;
	x = std::fabs(x);
	x = std::min(x, input_max);

	mant = frexp_1_2(x, &exp);
	exp = x == 0.0f ? -127 : exp;
	exp = std::max(exp, exponent_min) + 127;

	mantpart = T::horner[0];
	for (unsigned i = 1; i < sizeof(T::horner) / sizeof(T::horner[0]); ++i) {
		mantpart = std::fma(mantpart, mant, T::horner[i]);
	}

	exppart = T::table[exp & (sizeof(T::table) / sizeof(T::table[0]) - 1)];
	return std::copysign(mantpart * exppart, orig);
}

template <class T, bool Eotf>
float srgb_power_function(float x)
{
	float orig = x;
	x = std::fabs(x);

	if (x > T::knee) {
		if (Eotf)
			x = std::fma(x, T::power_scale, T::power_offset);

		x = power_function<T>(x);

		if (!Eotf)
			x = std::fma(x, T::power_scale, T::power_offset);
	} else {
		x = T::linear_scale * x;
	}

	return std::copysign(x, orig);
}

template <class T, bool Log>
float segmented_polynomial(float x)
{
	float result;
	int idx;

	x = std::max(x, FLT_MIN);

	if (Log) {
		int exp;
		frexp_1_2(x, &exp);
		exp = std::min(std::max(exp, -32), -1);
		idx = (exp + 127) & (sizeof(T::horner0) / sizeof(T::horner0[0]) - 1);
	} else {
		float tmp = std::min(std::max(x, 0.0f), std::nextafterf(1.0f, -INFINITY));
		idx = static_cast<int>(tmp * 32);
	}

	result = T::horner0[idx];
	result = std::fma(result, x, T::horner1[idx]);
	result = std::fma(result, x, T::horner2[idx]);
	result = std::fma(result, x, T::horner3[idx]);
	result = std::fma(result, x, T::horner4[idx]);

	return std::max(result, 0.0f);
}

} // namespace


float rec_1886_eotf(float x)
{
	return power_function<Rec1886EOTF>(x);
}

float rec_1886_inverse_eotf(float x)
{
	return power_function<Rec1886InverseEOTF>(x);
}

float srgb_eotf(float x)
{
	return srgb_power_function<SRGBEOTF, true>(x);
}

float srgb_inverse_eotf(float x)
{
	return srgb_power_function<SRGBInverseEOTF, false>(x);
}

float st_2084_eotf(float x)
{
	return segmented_polynomial<ST2084EOTF, false>(x);
}

float st_2084_inverse_eotf(float x)
{
	return segmented_polynomial<ST2084InverseEOTF, true>(x);
}

} // namespace avx512constants
} // namespace colorspace
} // namespace zimg

#endif // ZIMG_X86_AVX512
