
int BIO_vsnprintf(char *buf,size_t n,char *format,va_list args)

{
  undefined *puVar1;
  int iVar2;
  size_t local_res4 [3];
  char *local_1c [2];
  int local_14;
  int local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_res4[0] = n;
  local_1c[0] = buf;
  iVar2 = _dopr(local_1c,0,local_res4,&local_14,&local_10,format,args);
  if ((iVar2 == 0) || (local_10 != 0)) {
    local_14 = -1;
  }
  else if (local_14 < 0) {
    local_14 = -1;
  }
  if (local_c == *(int *)puVar1) {
    return local_14;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x00526240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_fwrite_006a9a74)();
  return iVar2;
}

