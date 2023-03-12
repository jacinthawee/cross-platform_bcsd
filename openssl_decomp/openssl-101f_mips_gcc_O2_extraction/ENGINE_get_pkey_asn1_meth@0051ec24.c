
EVP_PKEY_ASN1_METHOD * ENGINE_get_pkey_asn1_meth(ENGINE *e,int nid)

{
  undefined *puVar1;
  int iVar2;
  EVP_PKEY_ASN1_METHOD *local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((*(code **)(e + 0x30) == (code *)0x0) ||
     (iVar2 = (**(code **)(e + 0x30))(e,&local_10,0,nid), iVar2 == 0)) {
    ERR_put_error(0x26,0xc1,0x65,"tb_asnmth.c",0x81);
    local_10 = (EVP_PKEY_ASN1_METHOD *)0x0;
  }
  if (local_c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return *(EVP_PKEY_ASN1_METHOD **)(local_c + 0x30);
  }
  return local_10;
}

