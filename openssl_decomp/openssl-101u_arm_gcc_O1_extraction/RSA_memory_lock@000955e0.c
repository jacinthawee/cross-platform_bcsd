
int RSA_memory_lock(RSA *r)

{
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  BIGNUM *a;
  BIGNUM *pBVar5;
  ulong *__dest;
  BIGNUM ***pppBVar6;
  BIGNUM **ppBStack_44;
  BIGNUM **local_40 [7];
  
  if (r->d != (BIGNUM *)0x0) {
    local_40[0] = &r->d;
    local_40[1] = &r->p;
    local_40[2] = &r->q;
    local_40[3] = &r->dmp1;
    local_40[4] = &r->dmq1;
    local_40[5] = &r->iqmp;
    pBVar1 = (BIGNUM *)
             CRYPTO_malloc_locked
                       ((r->d->top + r->p->top + r->q->top + r->dmp1->top + r->dmq1->top +
                         r->iqmp->top + 0x20) * 4,"rsa_lib.c",0x13a);
    if (pBVar1 == (BIGNUM *)0x0) {
      ERR_put_error(4,0x82,0x41,"rsa_lib.c",0x13b);
    }
    else {
      __dest = (ulong *)((int)&pBVar1[1].dmax + 3);
      pppBVar6 = &ppBStack_44;
      pBVar5 = pBVar1;
      do {
        pppBVar6 = pppBVar6 + 1;
        a = **pppBVar6;
        **pppBVar6 = pBVar5;
        iVar2 = a->top;
        iVar3 = a->dmax;
        iVar4 = a->neg;
        pBVar5->d = a->d;
        pBVar5->top = iVar2;
        pBVar5->neg = iVar4;
        pBVar5->dmax = iVar3;
        pBVar5->flags = 2;
        pBVar5->d = __dest;
        memcpy(__dest,a->d,a->top << 2);
        __dest = __dest + a->top;
        BN_clear_free(a);
        pBVar5 = pBVar5 + 1;
      } while (pppBVar6 != local_40 + 5);
      r->bignum_data = (char *)pBVar1;
      r->flags = r->flags & 0xfffffff9;
      pBVar1 = (BIGNUM *)0x1;
    }
    return (int)pBVar1;
  }
  return 1;
}

