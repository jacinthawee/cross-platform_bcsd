
void ssl2_mac(int param_1,uchar *param_2,int param_3)

{
  int iVar1;
  size_t cnt;
  undefined4 uVar2;
  size_t cnt_00;
  void *d;
  void *d_00;
  EVP_MD_CTX EStack_40;
  undefined local_28;
  undefined local_27;
  undefined local_26;
  undefined local_25;
  int local_24;
  
  local_24 = __TMC_END__;
  if (param_3 == 0) {
    iVar1 = *(int *)(param_1 + 0x54);
    uVar2 = *(undefined4 *)(iVar1 + 0xd0);
    d_00 = *(void **)(iVar1 + 0x5c);
    cnt_00 = *(size_t *)(iVar1 + 0x44);
    d = *(void **)(iVar1 + 0x50);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x54);
    uVar2 = *(undefined4 *)(iVar1 + 0xd4);
    d_00 = *(void **)(iVar1 + 0x60);
    cnt_00 = *(size_t *)(iVar1 + 0x4c);
    d = *(void **)(iVar1 + 0x54);
  }
  local_27 = (undefined)((uint)uVar2 >> 0x10);
  local_25 = (undefined)uVar2;
  local_28 = (undefined)((uint)uVar2 >> 0x18);
  local_26 = (undefined)((uint)uVar2 >> 8);
  EVP_MD_CTX_init(&EStack_40);
  EVP_MD_CTX_copy(&EStack_40,*(EVP_MD_CTX **)(param_1 + 0x84));
  cnt = EVP_CIPHER_CTX_key_length(*(EVP_CIPHER_CTX **)(param_1 + 0x80));
  EVP_DigestUpdate(&EStack_40,d_00,cnt);
  EVP_DigestUpdate(&EStack_40,d,cnt_00);
  EVP_DigestUpdate(&EStack_40,&local_28,4);
  EVP_DigestFinal_ex(&EStack_40,param_2,(uint *)0x0);
  EVP_MD_CTX_cleanup(&EStack_40);
  if (local_24 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

