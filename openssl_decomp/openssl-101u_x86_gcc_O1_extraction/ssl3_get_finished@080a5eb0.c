
size_t ssl3_get_finished(int param_1,undefined4 param_2,undefined4 param_3)

{
  size_t len;
  undefined4 uVar1;
  int iVar2;
  int in_GS_OFFSET;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  len = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,param_2,param_3,0x14,0x40,&local_14);
  if (local_14 != 0) {
    iVar2 = *(int *)(param_1 + 0x58);
    if (*(int *)(iVar2 + 0x180) == 0) {
      ERR_put_error(0x14,0x8c,0x9a,"s3_both.c",0x108);
      uVar1 = 10;
    }
    else {
      *(undefined4 *)(iVar2 + 0x180) = 0;
      if (len == *(size_t *)(iVar2 + 0x338)) {
        iVar2 = CRYPTO_memcmp(*(void **)(param_1 + 0x40),(void *)(iVar2 + 0x2b8),len);
        if (iVar2 == 0) {
          if (*(int *)(param_1 + 4) == 0x2000) {
            if (0x40 < (int)len) {
              OpenSSLDie("s3_both.c",0x120,"i <= EVP_MAX_MD_SIZE");
            }
            memcpy((void *)(*(int *)(param_1 + 0x58) + 0x394),
                   (void *)(*(int *)(param_1 + 0x58) + 0x2b8),len);
            *(char *)(*(int *)(param_1 + 0x58) + 0x3d4) = (char)len;
            len = 1;
          }
          else {
            if (0x40 < (int)len) {
              OpenSSLDie("s3_both.c",0x124,"i <= EVP_MAX_MD_SIZE");
            }
            memcpy((void *)(*(int *)(param_1 + 0x58) + 0x3d5),
                   (void *)(*(int *)(param_1 + 0x58) + 0x2b8),len);
            *(char *)(*(int *)(param_1 + 0x58) + 0x415) = (char)len;
            len = 1;
          }
          goto LAB_080a5f3d;
        }
        ERR_put_error(0x14,0x8c,0x95,"s3_both.c",0x118);
        uVar1 = 0x33;
      }
      else {
        ERR_put_error(0x14,0x8c,0x6f,"s3_both.c",0x112);
        uVar1 = 0x32;
      }
    }
    ssl3_send_alert(param_1,2,uVar1);
    len = 0;
  }
LAB_080a5f3d:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return len;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

