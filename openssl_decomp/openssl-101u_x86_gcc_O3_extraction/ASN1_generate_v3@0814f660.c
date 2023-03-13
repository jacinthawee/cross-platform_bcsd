
ASN1_TYPE * ASN1_generate_v3(char *str,X509V3_CTX *cnf)

{
  ASN1_TYPE *pAVar1;
  int in_GS_OFFSET;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = 0;
  pAVar1 = (ASN1_TYPE *)generate_v3(&local_14);
  if (local_14 != 0) {
    ERR_put_error(0xd,0xb2,local_14,"asn1_gen.c",0x90);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

