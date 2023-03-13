
void ERR_error_string_n(ulong e,char *buf,size_t len)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  char *pcVar6;
  undefined1 *puVar7;
  char *pcVar8;
  uint uVar9;
  char *buf_00;
  int in_GS_OFFSET;
  uint local_e8 [2];
  char local_e0 [64];
  char local_a0 [64];
  char local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = e >> 0x18;
  uVar2 = e >> 0xc & 0xfff;
  uVar3 = e & 0xfff;
  if (err_fns == (undefined1 *)0x0) {
    puVar7 = err_fns;
    CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    CRYPTO_lock((int)puVar7,10,(char *)0x1,(int)"err.c");
  }
  uVar9 = uVar1 << 0x18;
  local_e8[0] = uVar9;
  iVar4 = (**(code **)(err_fns + 8))(local_e8);
  if (iVar4 == 0) {
    pcVar6 = (char *)0x0;
  }
  else {
    pcVar6 = *(char **)(iVar4 + 4);
  }
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(iVar4,9,(char *)0x1,(int)"err.c");
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    CRYPTO_lock(iVar4,10,(char *)0x1,(int)"err.c");
  }
  local_e8[0] = uVar2 << 0xc | uVar9;
  iVar4 = (**(code **)(err_fns + 8))(local_e8);
  if (iVar4 == 0) {
    pcVar8 = (char *)0x0;
  }
  else {
    pcVar8 = *(char **)(iVar4 + 4);
  }
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
    puVar7 = err_fns;
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    CRYPTO_lock((int)puVar7,10,(char *)0x1,(int)"err.c");
  }
  local_e8[0] = uVar9 | uVar3;
  iVar4 = (**(code **)(err_fns + 8))(local_e8);
  if (iVar4 == 0) {
    buf_00 = (char *)0x0;
    local_e8[0] = uVar3;
    iVar4 = (**(code **)(err_fns + 8))(local_e8);
    if (iVar4 != 0) goto LAB_081223bf;
  }
  else {
LAB_081223bf:
    buf_00 = *(char **)(iVar4 + 4);
  }
  if (pcVar6 == (char *)0x0) {
    BIO_snprintf(local_e0,0x40,"lib(%lu)",uVar1);
  }
  if (pcVar8 == (char *)0x0) {
    pcVar8 = local_a0;
    BIO_snprintf(pcVar8,0x40,"func(%lu)",uVar2);
    if (buf_00 == (char *)0x0) {
      buf_00 = local_60;
      BIO_snprintf(buf_00,0x40,"reason(%lu)",uVar3);
    }
  }
  else if (buf_00 == (char *)0x0) {
    buf_00 = local_60;
    BIO_snprintf(buf_00,0x40,"reason(%lu)",uVar3,uVar3,pcVar8);
  }
  if (pcVar6 == (char *)0x0) {
    pcVar6 = local_e0;
  }
  BIO_snprintf(buf,len,"error:%08lX:%s:%s:%s",e,pcVar6,pcVar8,buf_00);
  sVar5 = strlen(buf);
  if ((len - 1 != sVar5) || (len < 5)) goto LAB_081224cc;
  pcVar6 = strchr(buf,0x3a);
  if ((pcVar6 == (char *)0x0) || (buf + (len - 5) < pcVar6)) {
    pcVar6 = buf + (len - 5);
    *pcVar6 = ':';
  }
  pcVar6 = strchr(pcVar6 + 1,0x3a);
  if (pcVar6 == (char *)0x0) {
    pcVar8 = buf + (len - 4);
LAB_08122478:
    *pcVar8 = ':';
    pcVar6 = pcVar8;
  }
  else {
    pcVar8 = buf + (len - 4);
    if (pcVar8 < pcVar6) goto LAB_08122478;
  }
  pcVar6 = strchr(pcVar6 + 1,0x3a);
  if (pcVar6 == (char *)0x0) {
    pcVar8 = buf + (len - 3);
LAB_081224a5:
    *pcVar8 = ':';
    pcVar6 = pcVar8;
  }
  else {
    pcVar8 = buf + (len - 3);
    if (pcVar8 < pcVar6) goto LAB_081224a5;
  }
  pcVar6 = strchr(pcVar6 + 1,0x3a);
  if (pcVar6 == (char *)0x0) {
    pcVar8 = buf + (len - 2);
  }
  else {
    pcVar8 = buf + (len - 2);
    if (pcVar6 <= pcVar8) goto LAB_081224cc;
  }
  *pcVar8 = ':';
LAB_081224cc:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

