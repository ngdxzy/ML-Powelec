#ifndef __TYPEDEF_HPP__
#define __TYPEDEF_HPP__


#include "hls_stream.h"
#include "ap_fixed.h"
#include "ap_axi_sdata.h"
#include "ap_shift_reg.h"

const int M = 64;
const int MD2 = M >> 1;
const int Diodes = 4;
const int Switches = 4;

typedef ap_fixed<32,14,AP_TRN_ZERO> d_htype;
typedef ap_fixed<64,28,AP_TRN_ZERO> d_htype_wide;
typedef ap_fixed<64,28,AP_TRN_ZERO> d_htype_acc;
typedef float d_stype;
typedef ap_uint<32> u32;
typedef ap_uint<8> u8;
typedef ap_uint<16> u16_bitwise;
typedef ap_uint<M> shift_bits;
typedef ap_uint<1> bit;
typedef ap_int<16> s16;

typedef hls::stream<d_htype> d_stream;
//typedef struct {
//	d_htype data;
//	bit last;
//	bit user;
//}dp;
typedef hls::axis<d_htype,1,0,0> dp;
typedef hls::axis<d_htype_wide,1,0,0> wdp;
typedef hls::stream<dp> dp_stream;
typedef hls::stream<wdp> wdp_stream;
typedef struct {
	d_htype data[MD2];
}Col;
typedef struct {
	d_htype data[4 * Diodes];
}x_picked;
typedef hls::stream<x_picked> x_picked_stream;
typedef hls::stream<Col> col_stream;

typedef struct {
	d_htype data[M + 1];
}SA_array;
typedef hls::axis<SA_array,1,0,0> SA_dp;
typedef hls::stream<SA_dp> SA_stream;
typedef hls::stream<u16_bitwise> Ctrl_Stream;

#endif
