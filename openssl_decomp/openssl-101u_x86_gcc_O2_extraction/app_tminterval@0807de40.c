
float10 app_tminterval(int param_1,int param_2)

{
  clock_t cVar1;
  long lVar2;
  int in_GS_OFFSET;
  float10 fVar3;
  tms local_20;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  cVar1 = times(&local_20);
  if (param_2 != 0) {
    cVar1 = local_20.tms_utime;
  }
  if (param_1 == 0) {
    fVar3 = (float10)0;
    tmstart_17448 = cVar1;
  }
  else {
    lVar2 = sysconf(2);
    fVar3 = (float10)(cVar1 - tmstart_17448) / (float10)lVar2;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return fVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

