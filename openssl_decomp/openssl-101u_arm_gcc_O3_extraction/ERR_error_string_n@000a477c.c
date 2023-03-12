
void ERR_error_string_n(ulong e,char *buf,size_t len)

{
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  uint uVar4;
  char *pcVar5;
  char *local_108;
  uint local_f4 [2];
  char acStack_ec [64];
  char acStack_ac [64];
  char acStack_6c [64];
  int local_2c;
  
  uVar4 = (e << 8) >> 0x14;
  local_2c = __stack_chk_guard;
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  local_f4[0] = e & 0xff000000;
  local_108 = (char *)(**(code **)(err_fns + 8))(local_f4);
  if (local_108 != (char *)0x0) {
    local_108 = *(char **)(local_108 + 4);
  }
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  local_f4[0] = e & 0xff000000 | uVar4 << 0xc;
  pcVar1 = (char *)(**(code **)(err_fns + 8))(local_f4);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = *(char **)(pcVar1 + 4);
  }
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  local_f4[0] = e & 0xff000fff;
  pcVar2 = (char *)(**(code **)(err_fns + 8))(local_f4);
  if ((pcVar2 != (char *)0x0) ||
     (local_f4[0] = e & 0xfff, pcVar2 = (char *)(**(code **)(err_fns + 8))(local_f4),
     pcVar2 != (char *)0x0)) {
    pcVar2 = *(char **)(pcVar2 + 4);
  }
  if (local_108 == (char *)0x0) {
    BIO_snprintf(acStack_ec,0x40,"lib(%lu)",e >> 0x18);
  }
  if (pcVar1 == (char *)0x0) {
    BIO_snprintf(acStack_ac,0x40,"func(%lu)",uVar4);
  }
  if (pcVar2 == (char *)0x0) {
    BIO_snprintf(acStack_6c,0x40,"reason(%lu)",e & 0xfff);
  }
  if (local_108 == (char *)0x0) {
    local_108 = acStack_ec;
  }
  pcVar5 = acStack_ac;
  if (pcVar1 != (char *)0x0) {
    pcVar5 = pcVar1;
  }
  if (pcVar2 == (char *)0x0) {
    pcVar2 = acStack_6c;
  }
  BIO_snprintf(buf,len,"error:%08lX:%s:%s:%s",e,local_108,pcVar5,pcVar2);
  sVar3 = strlen(buf);
  if ((sVar3 != len - 1) || (len < 5)) goto LAB_000a4868;
  pcVar1 = strchr(buf,0x3a);
  if ((pcVar1 == (char *)0x0) || (buf + (len - 5) < pcVar1)) {
    pcVar1 = buf + (len - 5);
    *pcVar1 = ':';
  }
  pcVar1 = strchr(pcVar1 + 1,0x3a);
  if (pcVar1 == (char *)0x0) {
    pcVar2 = buf + (len - 4);
LAB_000a48b6:
    *pcVar2 = ':';
    pcVar1 = pcVar2;
  }
  else {
    pcVar2 = buf + (len - 4);
    if (pcVar2 < pcVar1) goto LAB_000a48b6;
  }
  pcVar1 = strchr(pcVar1 + 1,0x3a);
  if (pcVar1 == (char *)0x0) {
    pcVar2 = buf + (len - 3);
LAB_000a48d4:
    *pcVar2 = ':';
    pcVar1 = pcVar2;
  }
  else {
    pcVar2 = buf + (len - 3);
    if (pcVar2 < pcVar1) goto LAB_000a48d4;
  }
  pcVar1 = strchr(pcVar1 + 1,0x3a);
  if ((pcVar1 == (char *)0x0) || (buf + (len - 2) < pcVar1)) {
    buf[len - 2] = ':';
  }
LAB_000a4868:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

