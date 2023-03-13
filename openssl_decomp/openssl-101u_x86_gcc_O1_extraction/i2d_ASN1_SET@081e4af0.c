
int i2d_ASN1_SET(stack_st_OPENSSL_BLOCK *a,uchar **pp,undefined1 *i2d,int ex_tag,int ex_class,
                int is_set)

{
  uchar *__dest;
  int iVar1;
  void *pvVar2;
  int iVar3;
  uchar **__base;
  size_t __nmemb;
  uchar *__src;
  int iVar4;
  int iVar5;
  size_t __n;
  uchar **ppuVar6;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if (a != (stack_st_OPENSSL_BLOCK *)0x0) {
    iVar1 = sk_num(&a->stack);
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      iVar4 = 0;
LAB_081e4ba0:
      iVar1 = ASN1_object_size(1,iVar4,ex_tag);
      if ((pp != (uchar **)0x0) && (iVar1 != -1)) {
        local_24 = *pp;
        ASN1_put_object(&local_24,1,iVar4,ex_tag,ex_class);
        if ((is_set == 0) || (iVar4 = sk_num(&a->stack), __dest = local_24, iVar4 < 2)) {
          for (iVar4 = 0; iVar5 = sk_num(&a->stack), iVar4 < iVar5; iVar4 = iVar4 + 1) {
            pvVar2 = sk_value(&a->stack,iVar4);
            (*(code *)i2d)(pvVar2,&local_24);
          }
          *pp = local_24;
        }
        else {
          iVar4 = sk_num(&a->stack);
          __base = (uchar **)CRYPTO_malloc(iVar4 << 3,"a_set.c",0x81);
          if (__base == (uchar **)0x0) {
            iVar1 = 0x83;
          }
          else {
            ppuVar6 = __base;
            for (iVar4 = 0; iVar5 = sk_num(&a->stack), iVar4 < iVar5; iVar4 = iVar4 + 1) {
              *ppuVar6 = local_24;
              pvVar2 = sk_value(&a->stack,iVar4);
              (*(code *)i2d)(pvVar2,&local_24);
              ppuVar6[1] = local_24 + -(int)*ppuVar6;
              ppuVar6 = ppuVar6 + 2;
            }
            *pp = local_24;
            __n = (int)local_24 - (int)__dest;
            __nmemb = sk_num(&a->stack);
            qsort(__base,__nmemb,8,SetBlobCmp);
            __src = (uchar *)CRYPTO_malloc(__n,"a_set.c",0x95);
            if (__src != (uchar *)0x0) {
              ppuVar6 = __base + 1;
              local_24 = __src;
              for (iVar4 = 0; iVar5 = sk_num(&a->stack), iVar4 < iVar5; iVar4 = iVar4 + 1) {
                memcpy(local_24,ppuVar6[-1],(size_t)*ppuVar6);
                local_24 = local_24 + (int)*ppuVar6;
                ppuVar6 = ppuVar6 + 2;
              }
              memcpy(__dest,__src,__n);
              CRYPTO_free(__src);
              CRYPTO_free(__base);
              goto LAB_081e4b82;
            }
            iVar1 = 0x96;
          }
          ERR_put_error(0xd,0xbc,0x41,"a_set.c",iVar1);
          iVar1 = 0;
        }
      }
    }
    else {
      iVar4 = 0;
      pvVar2 = sk_value(&a->stack,iVar1);
      (*(code *)i2d)(pvVar2,0);
      do {
        iVar5 = iVar1 + -1;
        pvVar2 = sk_value(&a->stack,iVar1);
        iVar1 = (*(code *)i2d)(pvVar2,0);
        iVar4 = iVar4 + iVar1;
        if (iVar5 == -1) goto LAB_081e4ba0;
        pvVar2 = sk_value(&a->stack,iVar5);
        iVar3 = (*(code *)i2d)(pvVar2,0);
        iVar1 = iVar5;
      } while (iVar3 <= 0x7fffffff - iVar4);
      iVar1 = -1;
    }
  }
LAB_081e4b82:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

