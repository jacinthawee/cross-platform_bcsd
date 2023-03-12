
undefined4 register_ameth_gost(int param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  code *pcVar3;
  code *pcVar4;
  code *pcVar5;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_asn1_new_006a9870)(param_1,4);
  *param_2 = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  if (param_1 == 0x32c) {
    (*(code *)PTR_EVP_PKEY_asn1_set_free_006a9874)(iVar1,pkey_free_gost94);
    (*(code *)PTR_EVP_PKEY_asn1_set_private_006a987c)
              (*param_2,priv_decode_gost,priv_encode_gost,priv_print_gost94);
    (*(code *)PTR_EVP_PKEY_asn1_set_param_006a9880)
              (*param_2,gost94_param_decode,gost94_param_encode,param_missing_gost94,
               param_copy_gost94,param_cmp_gost94,param_print_gost94);
    iVar1 = *param_2;
    pcVar5 = pub_cmp_gost94;
    pcVar4 = pub_encode_gost94;
    pcVar3 = pub_decode_gost94;
    pcVar2 = pub_print_gost94;
  }
  else {
    if (param_1 == 0x32f) {
      (*(code *)PTR_EVP_PKEY_asn1_set_free_006a9874)(iVar1,mackey_free_gost);
      (*(code *)PTR_EVP_PKEY_asn1_set_ctrl_006a9878)(*param_2,mac_ctrl_gost);
      return 1;
    }
    if (param_1 != 0x32b) {
      return 1;
    }
    (*(code *)PTR_EVP_PKEY_asn1_set_free_006a9874)(iVar1,pkey_free_gost01);
    (*(code *)PTR_EVP_PKEY_asn1_set_private_006a987c)
              (*param_2,priv_decode_gost,priv_encode_gost,priv_print_gost01);
    (*(code *)PTR_EVP_PKEY_asn1_set_param_006a9880)
              (*param_2,gost2001_param_decode,gost2001_param_encode,param_missing_gost01,
               param_copy_gost01,param_cmp_gost01,param_print_gost01);
    iVar1 = *param_2;
    pcVar5 = pub_cmp_gost01;
    pcVar4 = pub_encode_gost01;
    pcVar3 = pub_decode_gost01;
    pcVar2 = pub_print_gost01;
  }
  (*(code *)PTR_EVP_PKEY_asn1_set_public_006a9884)
            (iVar1,pcVar3,pcVar4,pcVar5,pcVar2,pkey_size_gost,pkey_bits_gost);
  (*(code *)PTR_EVP_PKEY_asn1_set_ctrl_006a9878)(*param_2,pkey_ctrl_gost);
  return 1;
}

