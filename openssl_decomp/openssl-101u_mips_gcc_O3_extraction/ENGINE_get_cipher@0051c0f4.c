
EVP_CIPHER * ENGINE_get_cipher(ENGINE *e,int nid)

{
  undefined *puVar1;
  int iVar2;
  EVP_CIPHER *local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((*(code **)(e + 0x24) == (code *)0x0) ||
     (iVar2 = (**(code **)(e + 0x24))(e,&local_10,0,nid), iVar2 == 0)) {
    ERR_put_error(0x26,0xb9,0x92,"tb_cipher.c",0x7e);
    local_10 = (EVP_CIPHER *)0x0;
  }
  if (local_c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return *(EVP_CIPHER **)(local_c + 0x24);
  }
  return local_10;
}

