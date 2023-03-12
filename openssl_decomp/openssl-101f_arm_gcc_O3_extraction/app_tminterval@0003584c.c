
double app_tminterval(int param_1,int param_2)

{
  clock_t cVar1;
  long lVar2;
  tms local_20;
  
  cVar1 = times(&local_20);
  if (param_2 != 0) {
    cVar1 = local_20.tms_utime;
  }
  if (param_1 == 0) {
    tmstart_20032 = cVar1;
    return DAT_000358a0;
  }
  lVar2 = sysconf(2);
  return (double)(longlong)(cVar1 - tmstart_20032) / (double)(longlong)lVar2;
}

