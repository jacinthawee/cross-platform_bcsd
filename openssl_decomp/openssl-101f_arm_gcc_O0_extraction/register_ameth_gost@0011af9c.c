
undefined4
register_ameth_gost(int param_1,EVP_PKEY_ASN1_METHOD **param_2,char *param_3,char *param_4)

{
  code *pcVar1;
  code *pcVar2;
  code *pcVar3;
  code *pcVar4;
  EVP_PKEY_ASN1_METHOD *pEVar5;
  
  pEVar5 = EVP_PKEY_asn1_new(param_1,4,param_3,param_4);
  *param_2 = pEVar5;
  if (pEVar5 == (EVP_PKEY_ASN1_METHOD *)0x0) {
    return 0;
  }
  if (param_1 == 0x32c) {
    EVP_PKEY_asn1_set_free(pEVar5,(pkey_free *)&pkey_free_gost94_1);
    EVP_PKEY_asn1_set_private
              (*param_2,priv_decode_gost + 1,priv_encode_gost + 1,priv_print_gost94 + 1);
    EVP_PKEY_asn1_set_param
              (*param_2,gost94_param_decode + 1,gost94_param_encode + 1,param_missing_gost94 + 1,
               param_copy_gost94 + 1,param_cmp_gost94 + 1,param_print_gost94 + 1);
    pEVar5 = *param_2;
    pcVar4 = pub_print_gost94;
    pcVar2 = pub_decode_gost94;
    pcVar3 = pub_encode_gost94;
    pcVar1 = pub_cmp_gost94;
  }
  else {
    if (param_1 == 0x32f) {
      EVP_PKEY_asn1_set_free(pEVar5,mackey_free_gost + 1);
      EVP_PKEY_asn1_set_ctrl(*param_2,mac_ctrl_gost + 1);
      return 1;
    }
    if (param_1 != 0x32b) {
      return 1;
    }
    EVP_PKEY_asn1_set_free(pEVar5,pkey_free_gost01 + 1);
    EVP_PKEY_asn1_set_private
              (*param_2,priv_decode_gost + 1,priv_encode_gost + 1,priv_print_gost01 + 1);
    EVP_PKEY_asn1_set_param
              (*param_2,gost2001_param_decode + 1,gost2001_param_encode + 1,param_missing_gost01 + 1
               ,param_copy_gost01 + 1,param_cmp_gost01 + 1,param_print_gost01 + 1);
    pcVar2 = pub_decode_gost01;
    pcVar3 = pub_encode_gost01;
    pcVar1 = pub_cmp_gost01;
    pEVar5 = *param_2;
    pcVar4 = pub_print_gost01;
  }
  EVP_PKEY_asn1_set_public
            (pEVar5,pcVar2 + 1,pcVar3 + 1,pcVar1 + 1,pcVar4 + 1,(pkey_size *)0x119bf9,
             pkey_bits_gost + 1);
  EVP_PKEY_asn1_set_ctrl(*param_2,pkey_ctrl_gost + 1);
  return 1;
}

