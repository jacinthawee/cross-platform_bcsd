
EVP_PKEY_METHOD * ENGINE_get_pkey_meth(ENGINE *e,int nid)

{
  undefined *puVar1;
  int iVar2;
  EVP_PKEY_METHOD *local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((*(code **)(e + 0x2c) == (code *)0x0) ||
     (iVar2 = (**(code **)(e + 0x2c))(e,&local_10,0,nid), iVar2 == 0)) {
    ERR_put_error(0x26,0xc0,0x65,"tb_pkmeth.c",0x7f);
    local_10 = (EVP_PKEY_METHOD *)0x0;
  }
  if (local_c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return *(EVP_PKEY_METHOD **)(local_c + 0x2c);
  }
  return local_10;
}

