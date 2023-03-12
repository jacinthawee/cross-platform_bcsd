
void ssl2_mac(int param_1,uchar *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  size_t cnt;
  void *d;
  size_t cnt_00;
  void *d_00;
  int in_GS_OFFSET;
  EVP_MD_CTX local_3c;
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = *(int *)(param_1 + 0x54);
  if (param_3 == 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0xd0);
    d = *(void **)(iVar1 + 0x5c);
    cnt_00 = *(size_t *)(iVar1 + 0x44);
    d_00 = *(void **)(iVar1 + 0x50);
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0xd4);
    d = *(void **)(iVar1 + 0x60);
    cnt_00 = *(size_t *)(iVar1 + 0x4c);
    d_00 = *(void **)(iVar1 + 0x54);
  }
  local_21 = (undefined)uVar2;
  local_24 = (undefined)((uint)uVar2 >> 0x18);
  local_23 = (undefined)((uint)uVar2 >> 0x10);
  local_22 = (undefined)((uint)uVar2 >> 8);
  EVP_MD_CTX_init(&local_3c);
  EVP_MD_CTX_copy(&local_3c,*(EVP_MD_CTX **)(param_1 + 0x84));
  cnt = EVP_CIPHER_CTX_key_length(*(EVP_CIPHER_CTX **)(param_1 + 0x80));
  EVP_DigestUpdate(&local_3c,d,cnt);
  EVP_DigestUpdate(&local_3c,d_00,cnt_00);
  EVP_DigestUpdate(&local_3c,&local_24,4);
  EVP_DigestFinal_ex(&local_3c,param_2,(uint *)0x0);
  EVP_MD_CTX_cleanup(&local_3c);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

