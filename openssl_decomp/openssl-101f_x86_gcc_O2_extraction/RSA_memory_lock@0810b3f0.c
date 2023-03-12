
int RSA_memory_lock(RSA *r)

{
  BIGNUM **ppBVar1;
  BIGNUM *a;
  BIGNUM *pBVar2;
  int iVar3;
  BIGNUM *pBVar4;
  ulong *__dest;
  BIGNUM ***pppBVar5;
  int in_GS_OFFSET;
  BIGNUM **local_38 [6];
  BIGNUM **local_20 [4];
  
  local_20[0] = *(BIGNUM ***)(in_GS_OFFSET + 0x14);
  if (r->d == (BIGNUM *)0x0) {
    iVar3 = 1;
  }
  else {
    local_38[0] = &r->d;
    local_38[1] = &r->p;
    local_38[2] = &r->q;
    local_38[3] = &r->dmp1;
    local_38[4] = &r->dmq1;
    local_38[5] = &r->iqmp;
    pBVar2 = (BIGNUM *)
             CRYPTO_malloc_locked
                       ((r->d->top + 1 + r->p->top + r->q->top + r->dmp1->top + r->dmq1->top +
                        r->iqmp->top) * 4 + 0x7c,"rsa_lib.c",0x135);
    if (pBVar2 == (BIGNUM *)0x0) {
      ERR_put_error(4,0x82,0x41,"rsa_lib.c",0x137);
      iVar3 = 0;
    }
    else {
      pppBVar5 = local_38;
      __dest = (ulong *)((int)&pBVar2[1].dmax + 3);
      pBVar4 = pBVar2;
      do {
        ppBVar1 = *pppBVar5;
        pppBVar5 = pppBVar5 + 1;
        a = *ppBVar1;
        *ppBVar1 = pBVar4;
        pBVar4->d = a->d;
        pBVar4->top = a->top;
        pBVar4->dmax = a->dmax;
        iVar3 = a->neg;
        pBVar4->flags = 2;
        pBVar4->d = __dest;
        pBVar4->neg = iVar3;
        memcpy(__dest,a->d,a->top << 2);
        __dest = __dest + a->top;
        BN_clear_free(a);
        pBVar4 = pBVar4 + 1;
      } while (pppBVar5 != local_20);
      r->flags = r->flags & 0xfffffff9;
      r->bignum_data = (char *)pBVar2;
      iVar3 = 1;
    }
  }
  if (local_20[0] == *(BIGNUM ***)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

