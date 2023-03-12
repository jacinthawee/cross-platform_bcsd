
int BIO_vsnprintf(char *buf,size_t n,char *format,va_list args)

{
  undefined *puVar1;
  int iVar2;
  size_t local_res4 [3];
  char *local_1c [2];
  int local_14;
  int local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_res4[0] = n;
  local_1c[0] = buf;
  _dopr_constprop_0(local_1c,local_res4,&local_14,&local_10,format,args);
  if (local_10 == 0) {
    if (local_14 < 0) {
      local_14 = -1;
    }
  }
  else {
    local_14 = -1;
  }
  if (local_c == *(int *)puVar1) {
    return local_14;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x00529660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_fwrite_006aab7c)();
  return iVar2;
}

