
EVP_PKEY_ASN1_METHOD * ENGINE_get_pkey_asn1_meth(ENGINE *e,int nid)

{
  int iVar1;
  int in_GS_OFFSET;
  EVP_PKEY_ASN1_METHOD *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(code **)(e + 0x30) == (code *)0x0) ||
     (iVar1 = (**(code **)(e + 0x30))(e,&local_14,0,nid), iVar1 == 0)) {
    ERR_put_error(0x26,0xc1,0x65,"tb_asnmth.c",0x85);
    local_14 = (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_14;
}

