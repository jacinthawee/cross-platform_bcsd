
int i2d_ASN1_SET(stack_st_OPENSSL_BLOCK *a,uchar **pp,undefined1 *i2d,int ex_tag,int ex_class,
                int is_set)

{
  uchar **__dest;
  int iVar1;
  void *pvVar2;
  int iVar3;
  uchar **ppuVar4;
  uchar **__base;
  size_t __nmemb;
  uchar **ppuVar5;
  uchar **ppuVar6;
  int iVar7;
  size_t __n;
  uchar **local_2c [2];
  
  if (a == (stack_st_OPENSSL_BLOCK *)0x0) {
    return 0;
  }
  iVar1 = sk_num(&a->stack);
  iVar1 = iVar1 + -1;
  if (iVar1 < 0) {
    iVar7 = 0;
LAB_00120acc:
    ppuVar4 = (uchar **)ASN1_object_size(1,iVar7,ex_tag);
    if (pp != (uchar **)0x0 && ppuVar4 != (uchar **)0xffffffff) {
      iVar1 = 0;
      local_2c[0] = (uchar **)*pp;
      ASN1_put_object((uchar **)local_2c,1,iVar7,ex_tag,ex_class);
      if ((is_set == 0) || (iVar7 = sk_num(&a->stack), __dest = local_2c[0], iVar7 < 2)) {
        iVar1 = 0;
        while( true ) {
          iVar7 = sk_num(&a->stack);
          if (iVar7 <= iVar1) break;
          pvVar2 = sk_value(&a->stack,iVar1);
          (*(code *)i2d)(pvVar2,local_2c);
          iVar1 = iVar1 + 1;
        }
        *pp = (uchar *)local_2c[0];
        return (int)ppuVar4;
      }
      iVar7 = sk_num(&a->stack);
      __base = (uchar **)CRYPTO_malloc(iVar7 << 3,"a_set.c",0x81);
      ppuVar5 = __base;
      if (__base == (uchar **)0x0) {
        ERR_put_error(0xd,0xbc,0x41,"a_set.c",0x83);
        ppuVar4 = __base;
      }
      else {
        while( true ) {
          iVar7 = sk_num(&a->stack);
          if (iVar7 <= iVar1) break;
          *ppuVar5 = (uchar *)local_2c[0];
          pvVar2 = sk_value(&a->stack,iVar1);
          (*(code *)i2d)(pvVar2,local_2c);
          ppuVar5[1] = (uchar *)((int)local_2c[0] - (int)*ppuVar5);
          ppuVar5 = ppuVar5 + 2;
          iVar1 = iVar1 + 1;
        }
        *pp = (uchar *)local_2c[0];
        __n = (int)local_2c[0] - (int)__dest;
        __nmemb = sk_num(&a->stack);
        qsort(__base,__nmemb,8,SetBlobCmp + 1);
        ppuVar5 = (uchar **)CRYPTO_malloc(__n,"a_set.c",0x95);
        if (ppuVar5 == (uchar **)0x0) {
          ERR_put_error(0xd,0xbc,0x41,"a_set.c",0x96);
          ppuVar4 = ppuVar5;
        }
        else {
          ppuVar6 = __base;
          iVar1 = 0;
          local_2c[0] = ppuVar5;
          while( true ) {
            iVar7 = sk_num(&a->stack);
            if (iVar7 <= iVar1) break;
            memcpy(local_2c[0],*ppuVar6,(size_t)ppuVar6[1]);
            local_2c[0] = (uchar **)(ppuVar6[1] + (int)local_2c[0]);
            ppuVar6 = ppuVar6 + 2;
            iVar1 = iVar1 + 1;
          }
          memcpy(__dest,ppuVar5,__n);
          CRYPTO_free(ppuVar5);
          CRYPTO_free(__base);
        }
      }
    }
  }
  else {
    pvVar2 = sk_value(&a->stack,iVar1);
    (*(code *)i2d)(pvVar2,0);
    iVar7 = 0;
    do {
      pvVar2 = sk_value(&a->stack,iVar1);
      iVar3 = (*(code *)i2d)(pvVar2,0);
      iVar1 = iVar1 + -1;
      iVar7 = iVar7 + iVar3;
      if (iVar1 == -1) goto LAB_00120acc;
      pvVar2 = sk_value(&a->stack,iVar1);
      iVar3 = (*(code *)i2d)(pvVar2,0);
    } while (iVar3 <= 0x7fffffff - iVar7);
    ppuVar4 = (uchar **)0xffffffff;
  }
  return (int)ppuVar4;
}

