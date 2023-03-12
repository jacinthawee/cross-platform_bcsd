
int rc2_set_asn1_type_and_iv(EVP_CIPHER_CTX *param_1,ASN1_TYPE *param_2)

{
  long num;
  int iVar1;
  int in_GS_OFFSET;
  int local_24;
  int local_20;
  
  iVar1 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_2 != (ASN1_TYPE *)0x0) {
    num = 0x3a;
    EVP_CIPHER_CTX_ctrl(param_1,2,0,&local_24);
    if (((local_24 != 0x80) && (num = 0x78, local_24 != 0x40)) && (num = 0xa0, local_24 != 0x28)) {
      num = 0;
    }
    iVar1 = EVP_CIPHER_CTX_iv_length(param_1);
    iVar1 = ASN1_TYPE_set_int_octetstring(param_2,num,param_1->oiv,iVar1);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

