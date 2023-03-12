
void dtls1_send_finished(int param_1,int param_2,undefined4 param_3,undefined4 param_4,
                        undefined4 param_5)

{
  size_t __n;
  short sVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x34) != param_2) {
    dtls1_do_write(param_1,0x16,param_5,param_4);
    return;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
  __n = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x14))
                  (param_1,param_4,param_5,*(int *)(param_1 + 0x58) + 0x234);
  iVar2 = *(int *)(param_1 + 0x58);
  *(size_t *)(iVar2 + 0x2b4) = __n;
  memcpy((void *)(iVar3 + 0xc),(void *)(iVar2 + 0x234),__n);
  if (*(int *)(param_1 + 4) == 0x1000) {
    if (0x40 < (int)__n) {
      OpenSSLDie("d1_both.c",0x3a0,"i <= EVP_MAX_MD_SIZE");
    }
    memcpy((void *)(*(int *)(param_1 + 0x58) + 0x394),(void *)(*(int *)(param_1 + 0x58) + 0x234),__n
          );
    *(char *)(*(int *)(param_1 + 0x58) + 0x3d4) = (char)__n;
  }
  else {
    if (0x40 < (int)__n) {
      OpenSSLDie("d1_both.c",0x3a7,"i <= EVP_MAX_MD_SIZE");
    }
    memcpy((void *)(*(int *)(param_1 + 0x58) + 0x3d5),(void *)(*(int *)(param_1 + 0x58) + 0x234),__n
          );
    *(char *)(*(int *)(param_1 + 0x58) + 0x415) = (char)__n;
  }
  iVar2 = *(int *)(param_1 + 0x5c);
  if (*(int *)(iVar2 + 0x254) == 0) {
    sVar1 = *(short *)(iVar2 + 0x226);
    *(short *)(iVar2 + 0x226) = sVar1 + 1;
    *(short *)(iVar2 + 0x224) = sVar1;
  }
  else {
    sVar1 = *(short *)(iVar2 + 0x224);
  }
  *(short *)(iVar2 + 0x264) = sVar1;
  *(size_t *)(iVar2 + 0x260) = __n;
  *(size_t *)(iVar2 + 0x26c) = __n;
  *(undefined4 *)(iVar2 + 0x268) = 0;
  *(undefined *)(iVar2 + 0x25c) = 0x14;
  *(size_t *)(param_1 + 0x44) = __n + 0xc;
  *(undefined4 *)(param_1 + 0x48) = 0;
  dtls1_buffer_message(param_1,0);
  *(undefined4 *)(param_1 + 0x34) = param_3;
  dtls1_do_write(param_1,0x16);
  return;
}

