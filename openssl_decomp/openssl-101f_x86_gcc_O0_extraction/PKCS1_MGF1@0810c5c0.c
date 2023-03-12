
int PKCS1_MGF1(uchar *mask,long len,uchar *seed,long seedlen,EVP_MD *dgst)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  EVP_MD_CTX local_7c;
  undefined local_64;
  undefined local_63;
  undefined local_62;
  undefined local_61;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_7c);
  iVar1 = EVP_MD_size(dgst);
  if (iVar1 < 0) {
LAB_0810c738:
    iVar1 = -1;
  }
  else {
    if (0 < len) {
      iVar4 = 0;
      iVar3 = 0;
      do {
        local_61 = (undefined)iVar4;
        local_64 = (undefined)((uint)iVar4 >> 0x18);
        local_63 = (undefined)((uint)iVar4 >> 0x10);
        local_62 = (undefined)((uint)iVar4 >> 8);
        iVar2 = EVP_DigestInit_ex(&local_7c,dgst,(ENGINE *)0x0);
        if (((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&local_7c,seed,seedlen), iVar2 == 0)) ||
           (iVar2 = EVP_DigestUpdate(&local_7c,&local_64,4), iVar2 == 0)) goto LAB_0810c738;
        iVar2 = iVar1 + iVar3;
        if (len < iVar2) {
          iVar1 = EVP_DigestFinal_ex(&local_7c,local_60,(uint *)0x0);
          if (iVar1 == 0) goto LAB_0810c738;
          memcpy(mask + iVar3,local_60,len - iVar3);
          break;
        }
        iVar3 = EVP_DigestFinal_ex(&local_7c,mask + iVar3,(uint *)0x0);
        if (iVar3 == 0) goto LAB_0810c738;
        iVar4 = iVar4 + 1;
        iVar3 = iVar2;
      } while (iVar2 < len);
    }
    iVar1 = 0;
  }
  EVP_MD_CTX_cleanup(&local_7c);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

