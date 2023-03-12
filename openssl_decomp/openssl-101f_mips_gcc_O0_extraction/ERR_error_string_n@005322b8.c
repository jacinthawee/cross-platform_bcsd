
void ERR_error_string_n(ulong e,char *buf,size_t len)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *buf_00;
  char *pcVar4;
  char *pcVar5;
  uint local_f4 [2];
  char acStack_ec [64];
  char acStack_ac [64];
  char acStack_6c [64];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (err_fns == (undefined1 *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
  }
  local_f4[0] = e & 0xff000000;
  iVar2 = (**(code **)(err_fns + 8))(local_f4);
  if (iVar2 == 0) {
    pcVar4 = (char *)0x0;
  }
  else {
    pcVar4 = *(char **)(iVar2 + 4);
  }
  if (err_fns == (undefined1 *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
  }
  local_f4[0] = ((e << 8) >> 0x14) << 0xc | e & 0xff000000;
  iVar2 = (**(code **)(err_fns + 8))(local_f4);
  if (iVar2 == 0) {
    pcVar5 = (char *)0x0;
  }
  else {
    pcVar5 = *(char **)(iVar2 + 4);
  }
  if (err_fns == (undefined1 *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
  }
  local_f4[0] = e & 0xff000fff;
  iVar2 = (**(code **)(err_fns + 8))(local_f4);
  if (iVar2 == 0) {
    local_f4[0] = e & 0xfff;
    iVar2 = (**(code **)(err_fns + 8))(local_f4);
    if (iVar2 != 0) goto LAB_005323a8;
    pcVar3 = (char *)0x0;
  }
  else {
LAB_005323a8:
    pcVar3 = *(char **)(iVar2 + 4);
  }
  if (pcVar4 == (char *)0x0) {
    BIO_snprintf(acStack_ec,0x40,"lib(%lu)",e >> 0x18);
  }
  if (pcVar5 == (char *)0x0) {
    BIO_snprintf(acStack_ac,0x40,"func(%lu)",(e << 8) >> 0x14);
  }
  if (pcVar3 == (char *)0x0) {
    BIO_snprintf(acStack_6c,0x40,"reason(%lu)",e & 0xfff);
  }
  if (pcVar4 == (char *)0x0) {
    pcVar4 = acStack_ec;
  }
  if (pcVar5 == (char *)0x0) {
    pcVar5 = acStack_ac;
  }
  if (pcVar3 == (char *)0x0) {
    pcVar3 = acStack_6c;
  }
  buf_00 = (undefined1 *)len;
  BIO_snprintf(buf,len,"error:%08lX:%s:%s:%s",e,pcVar4,pcVar5,pcVar3);
  pcVar4 = buf;
  iVar2 = (*(code *)PTR_strlen_006aab30)();
  if ((iVar2 != len - 1) || (len < 5)) goto LAB_0053241c;
  pcVar4 = (char *)(*(code *)PTR_strchr_006aab34)(buf,0x3a);
  if ((pcVar4 == (char *)0x0) || (buf + (len - 5) < pcVar4)) {
    pcVar4 = buf + (len - 5);
    *pcVar4 = ':';
  }
  pcVar4 = (char *)(*(code *)PTR_strchr_006aab34)(pcVar4 + 1,0x3a);
  if (pcVar4 == (char *)0x0) {
    pcVar5 = buf + (len - 4);
LAB_005324c8:
    *pcVar5 = ':';
    pcVar4 = pcVar5;
  }
  else {
    pcVar5 = buf + (len - 4);
    if (pcVar5 < pcVar4) goto LAB_005324c8;
  }
  pcVar4 = (char *)(*(code *)PTR_strchr_006aab34)(pcVar4 + 1,0x3a);
  if (pcVar4 == (char *)0x0) {
    pcVar5 = buf + (len - 3);
LAB_00532500:
    *pcVar5 = ':';
    pcVar4 = pcVar5;
  }
  else {
    pcVar5 = buf + (len - 3);
    if (pcVar5 < pcVar4) goto LAB_00532500;
  }
  buf_00 = &DAT_0000003a;
  pcVar4 = pcVar4 + 1;
  pcVar5 = (char *)(*(code *)PTR_strchr_006aab34)();
  if ((pcVar5 == (char *)0x0) || (buf + (len - 2) < pcVar5)) {
    buf[len - 2] = ':';
  }
LAB_0053241c:
  if (local_2c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (buf_00 == (char *)0x0) {
    buf_00 = buf_5540;
  }
  ERR_error_string_n((ulong)pcVar4,buf_00,0x100);
  return;
}

