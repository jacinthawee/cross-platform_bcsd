
EVP_CIPHER * ENGINE_get_cipher(ENGINE *e,int nid)

{
  int iVar1;
  int in_GS_OFFSET;
  EVP_CIPHER *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(code **)(e + 0x24) == (code *)0x0) ||
     (iVar1 = (**(code **)(e + 0x24))(e,&local_14,0,nid), iVar1 == 0)) {
    ERR_put_error(0x26,0xb9,0x92,"tb_cipher.c",0x7e);
    local_14 = (EVP_CIPHER *)0x0;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_14;
}

