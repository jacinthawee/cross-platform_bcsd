
int PKCS1_MGF1(uchar *mask,long len,uchar *seed,long seedlen,EVP_MD *dgst)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  EVP_MD_CTX EStack_88;
  undefined local_70;
  undefined local_6f;
  undefined local_6e;
  undefined local_6d;
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  EVP_MD_CTX_init(&EStack_88);
  iVar1 = EVP_MD_size(dgst);
  if (iVar1 < 0) {
LAB_0009645a:
    iVar1 = -1;
  }
  else {
    if (0 < len) {
      iVar4 = 0;
      iVar3 = 0;
      do {
        local_6d = (undefined)iVar4;
        local_70 = (undefined)((uint)iVar4 >> 0x18);
        local_6f = (undefined)((uint)iVar4 >> 0x10);
        local_6e = (undefined)((uint)iVar4 >> 8);
        iVar2 = EVP_DigestInit_ex(&EStack_88,dgst,(ENGINE *)0x0);
        if (((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&EStack_88,seed,seedlen), iVar2 == 0)) ||
           (iVar2 = EVP_DigestUpdate(&EStack_88,&local_70,4), iVar2 == 0)) goto LAB_0009645a;
        iVar2 = iVar3 + iVar1;
        if (len < iVar2) {
          iVar1 = EVP_DigestFinal_ex(&EStack_88,auStack_6c,(uint *)0x0);
          if (iVar1 == 0) goto LAB_0009645a;
          iVar1 = 0;
          memcpy(mask + iVar3,auStack_6c,len - iVar3);
          goto LAB_00096442;
        }
        iVar3 = EVP_DigestFinal_ex(&EStack_88,mask + (iVar2 - iVar1),(uint *)0x0);
        if (iVar3 == 0) goto LAB_0009645a;
        iVar4 = iVar4 + 1;
        iVar3 = iVar2;
      } while (iVar2 < len);
    }
    iVar1 = 0;
  }
LAB_00096442:
  EVP_MD_CTX_cleanup(&EStack_88);
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

