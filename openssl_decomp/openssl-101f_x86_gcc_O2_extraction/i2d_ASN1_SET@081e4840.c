
int i2d_ASN1_SET(stack_st_OPENSSL_BLOCK *a,uchar **pp,undefined1 *i2d,int ex_tag,int ex_class,
                int is_set)

{
  uchar *__dest;
  int iVar1;
  int iVar2;
  void *pvVar3;
  uchar **__base;
  size_t __nmemb;
  uchar *__src;
  size_t __n;
  uchar **ppuVar4;
  int iVar5;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if (a != (stack_st_OPENSSL_BLOCK *)0x0) {
    iVar5 = 0;
    iVar2 = sk_num(&a->stack);
    iVar1 = iVar2 + -1;
    if (-1 < iVar2 + -1) {
      do {
        iVar2 = iVar1 + -1;
        pvVar3 = sk_value(&a->stack,iVar1);
        iVar1 = (*(code *)i2d)(pvVar3,0);
        iVar5 = iVar5 + iVar1;
        iVar1 = iVar2;
      } while (iVar2 != -1);
    }
    iVar1 = ASN1_object_size(1,iVar5,ex_tag);
    if (pp != (uchar **)0x0) {
      local_24 = *pp;
      ASN1_put_object(&local_24,1,iVar5,ex_tag,ex_class);
      if (is_set != 0) {
        iVar2 = sk_num(&a->stack);
        __dest = local_24;
        if (1 < iVar2) {
          iVar2 = sk_num(&a->stack);
          __base = (uchar **)CRYPTO_malloc(iVar2 << 3,"a_set.c",0x7b);
          if (__base == (uchar **)0x0) {
            iVar1 = 0x7e;
          }
          else {
            iVar2 = 0;
            ppuVar4 = __base;
            while( true ) {
              iVar5 = sk_num(&a->stack);
              if (iVar5 <= iVar2) break;
              *ppuVar4 = local_24;
              pvVar3 = sk_value(&a->stack,iVar2);
              (*(code *)i2d)(pvVar3,&local_24);
              ppuVar4[1] = local_24 + -(int)*ppuVar4;
              iVar2 = iVar2 + 1;
              ppuVar4 = ppuVar4 + 2;
            }
            *pp = local_24;
            __n = (int)local_24 - (int)__dest;
            __nmemb = sk_num(&a->stack);
            qsort(__base,__nmemb,8,SetBlobCmp);
            __src = (uchar *)CRYPTO_malloc(__n,"a_set.c",0x90);
            if (__src != (uchar *)0x0) {
              iVar2 = 0;
              ppuVar4 = __base + 1;
              local_24 = __src;
              while( true ) {
                iVar5 = sk_num(&a->stack);
                if (iVar5 <= iVar2) break;
                iVar2 = iVar2 + 1;
                memcpy(local_24,ppuVar4[-1],(size_t)*ppuVar4);
                local_24 = local_24 + (int)*ppuVar4;
                ppuVar4 = ppuVar4 + 2;
              }
              memcpy(__dest,__src,__n);
              CRYPTO_free(__src);
              CRYPTO_free(__base);
              goto LAB_081e4924;
            }
            iVar1 = 0x92;
          }
          ERR_put_error(0xd,0xbc,0x41,"a_set.c",iVar1);
          iVar1 = 0;
          goto LAB_081e4924;
        }
      }
      iVar2 = 0;
      while( true ) {
        iVar5 = sk_num(&a->stack);
        if (iVar5 <= iVar2) break;
        pvVar3 = sk_value(&a->stack,iVar2);
        (*(code *)i2d)(pvVar3,&local_24);
        iVar2 = iVar2 + 1;
      }
      *pp = local_24;
    }
  }
LAB_081e4924:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

