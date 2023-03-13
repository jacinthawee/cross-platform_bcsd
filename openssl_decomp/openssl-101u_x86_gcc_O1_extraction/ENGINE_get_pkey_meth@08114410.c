
EVP_PKEY_METHOD * ENGINE_get_pkey_meth(ENGINE *e,int nid)

{
  int iVar1;
  int in_GS_OFFSET;
  EVP_PKEY_METHOD *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(code **)(e + 0x2c) == (code *)0x0) ||
     (iVar1 = (**(code **)(e + 0x2c))(e,&local_14,0,nid), iVar1 == 0)) {
    ERR_put_error(0x26,0xc0,0x65,"tb_pkmeth.c",0x80);
    local_14 = (EVP_PKEY_METHOD *)0x0;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_14;
}

