
undefined4
register_ameth_gost(int param_1,EVP_PKEY_ASN1_METHOD **param_2,char *param_3,char *param_4)

{
  EVP_PKEY_ASN1_METHOD *ameth;
  code *pub_decode;
  code *pub_encode;
  code *pub_cmp;
  code *pub_print;
  
  ameth = EVP_PKEY_asn1_new(param_1,4,param_3,param_4);
  *param_2 = ameth;
  if (ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
    return 0;
  }
  if (param_1 == 0x32c) {
    EVP_PKEY_asn1_set_free(ameth,pkey_free_gost94);
    EVP_PKEY_asn1_set_private(*param_2,priv_decode_gost,priv_encode_gost,priv_print_gost94);
    EVP_PKEY_asn1_set_param
              (*param_2,gost94_param_decode,gost94_param_encode,param_missing_gost94,
               param_copy_gost94,param_cmp_gost94,param_print_gost94);
    pub_print = pub_print_gost94;
    pub_cmp = pub_cmp_gost94;
    pub_encode = pub_encode_gost94;
    pub_decode = pub_decode_gost94;
  }
  else {
    if (param_1 == 0x32f) {
      EVP_PKEY_asn1_set_free(ameth,mackey_free_gost);
      EVP_PKEY_asn1_set_ctrl(*param_2,mac_ctrl_gost);
      return 1;
    }
    if (param_1 != 0x32b) {
      return 1;
    }
    EVP_PKEY_asn1_set_free(ameth,pkey_free_gost01);
    EVP_PKEY_asn1_set_private(*param_2,priv_decode_gost,priv_encode_gost,priv_print_gost01);
    EVP_PKEY_asn1_set_param
              (*param_2,gost2001_param_decode,gost2001_param_encode,param_missing_gost01,
               param_copy_gost01,param_cmp_gost01,param_print_gost01);
    pub_print = pub_print_gost01;
    pub_cmp = pub_cmp_gost01;
    pub_encode = pub_encode_gost01;
    pub_decode = pub_decode_gost01;
  }
  EVP_PKEY_asn1_set_public
            (*param_2,pub_decode,pub_encode,pub_cmp,pub_print,pkey_size_gost,pkey_bits_gost);
  EVP_PKEY_asn1_set_ctrl(*param_2,pkey_ctrl_gost);
  return 1;
}

