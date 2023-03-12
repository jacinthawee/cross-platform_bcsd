
EVP_MD * ENGINE_get_digest(ENGINE *e,int nid)

{
  undefined *puVar1;
  int iVar2;
  EVP_MD *local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((*(code **)(e + 0x28) == (code *)0x0) ||
     (iVar2 = (**(code **)(e + 0x28))(e,&local_10,0,nid), iVar2 == 0)) {
    ERR_put_error(0x26,0xba,0x93,"tb_digest.c",0x7e);
    local_10 = (EVP_MD *)0x0;
  }
  if (local_c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return *(EVP_MD **)(local_c + 0x28);
  }
  return local_10;
}

