
EVP_MD * ENGINE_get_digest(ENGINE *e,int nid)

{
  int iVar1;
  int in_GS_OFFSET;
  EVP_MD *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(code **)(e + 0x28) == (code *)0x0) ||
     (iVar1 = (**(code **)(e + 0x28))(e,&local_14,0,nid), iVar1 == 0)) {
    ERR_put_error(0x26,0xba,0x93,"tb_digest.c",0x7e);
    local_14 = (EVP_MD *)0x0;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_14;
}

