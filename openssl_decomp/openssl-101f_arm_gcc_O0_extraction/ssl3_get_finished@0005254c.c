
size_t ssl3_get_finished(int param_1)

{
  size_t sVar1;
  int iVar2;
  void *a;
  undefined4 uVar3;
  size_t len;
  int local_14;
  
  sVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))();
  if (local_14 != 0) {
    iVar2 = *(int *)(param_1 + 0x58);
    if (*(int *)(iVar2 + 0x180) == 0) {
      ERR_put_error(0x14,0x8c,0x9a,"s3_both.c",0x103);
      uVar3 = 10;
    }
    else {
      len = *(size_t *)(iVar2 + 0x338);
      a = *(void **)(param_1 + 0x40);
      *(undefined4 *)(iVar2 + 0x180) = 0;
      if (len == sVar1) {
        iVar2 = CRYPTO_memcmp(a,(void *)(iVar2 + 0x2b8),len);
        if (iVar2 == 0) {
          if (*(int *)(param_1 + 4) != 0x2000) {
            if (0x40 < (int)len) {
              OpenSSLDie("s3_both.c",0x124,"i <= EVP_MAX_MD_SIZE");
            }
            memcpy((void *)(*(int *)(param_1 + 0x58) + 0x3d5),
                   (void *)(*(int *)(param_1 + 0x58) + 0x2b8),len);
            *(char *)(*(int *)(param_1 + 0x58) + 0x415) = (char)len;
            return 1;
          }
          if (0x40 < (int)len) {
            OpenSSLDie("s3_both.c",0x11d,"i <= EVP_MAX_MD_SIZE");
          }
          memcpy((void *)(*(int *)(param_1 + 0x58) + 0x394),
                 (void *)(*(int *)(param_1 + 0x58) + 0x2b8),len);
          *(char *)(*(int *)(param_1 + 0x58) + 0x3d4) = (char)len;
          return 1;
        }
        ERR_put_error(0x14,0x8c,0x95,"s3_both.c",0x115);
        uVar3 = 0x33;
      }
      else {
        ERR_put_error(0x14,0x8c,0x6f,"s3_both.c",0x10e);
        uVar3 = 0x32;
      }
    }
    ssl3_send_alert(param_1,2,uVar3);
    sVar1 = 0;
  }
  return sVar1;
}

