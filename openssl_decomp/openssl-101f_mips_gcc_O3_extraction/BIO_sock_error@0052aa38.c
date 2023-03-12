
int BIO_sock_error(int sock)

{
  undefined *puVar1;
  int iVar2;
  int local_14;
  undefined4 local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_10 = 4;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_getsockopt_006aab98)(sock,0xffff,0x1007,&local_14,&local_10);
  if (iVar2 < 0) {
    local_14 = 1;
  }
  if (local_c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x0052aacc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*(code *)PTR_gethostbyname_006aaa70)();
    return iVar2;
  }
  return local_14;
}

