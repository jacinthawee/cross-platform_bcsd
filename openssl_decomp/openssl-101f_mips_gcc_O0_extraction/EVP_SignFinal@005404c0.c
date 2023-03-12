
int EVP_SignFinal(EVP_MD_CTX *ctx,uchar *md,uint *s,EVP_PKEY *pkey)

{
  undefined *puVar1;
  int iVar2;
  EVP_MD *pEVar3;
  EVP_PKEY *sig;
  uint *****s_00;
  char *pkey_00;
  EVP_MD_CTX *pEVar4;
  EVP_PKEY_CTX *ctx_00;
  EVP_PKEY *unaff_s6;
  code *UNRECOVERED_JUMPTABLE;
  uint uStack_128;
  EVP_MD_CTX EStack_124;
  uchar auStack_10c [64];
  int iStack_cc;
  EVP_MD_CTX *pEStack_c8;
  undefined *puStack_c4;
  EVP_MD_CTX *pEStack_c0;
  uint *puStack_bc;
  EVP_PKEY *pEStack_b8;
  uchar *puStack_b4;
  EVP_PKEY *pEStack_b0;
  undefined4 uStack_ac;
  uint *****local_84;
  uint ****local_80;
  EVP_MD_CTX EStack_7c;
  EVP_PKEY aEStack_64 [2];
  EVP_MD_CTX *local_24;
  
  puStack_c4 = PTR___stack_chk_guard_006aabf0;
  pEStack_c8 = &EStack_7c;
  local_24 = *(EVP_MD_CTX **)PTR___stack_chk_guard_006aabf0;
  *s = 0;
  s_00 = (uint *****)s;
  pkey_00 = (char *)pkey;
  EVP_MD_CTX_init(pEStack_c8);
  sig = (EVP_PKEY *)ctx;
  iVar2 = EVP_MD_CTX_copy_ex(pEStack_c8,ctx);
  if (iVar2 == 0) {
LAB_00540560:
    pkey = (EVP_PKEY *)0x0;
    pEVar4 = (EVP_MD_CTX *)0x0;
    local_84 = s_00;
LAB_00540568:
    EVP_PKEY_CTX_free((EVP_PKEY_CTX *)pkey);
    pEStack_c8 = pEVar4;
  }
  else {
    unaff_s6 = aEStack_64;
    s_00 = (uint *****)&local_84;
    sig = unaff_s6;
    iVar2 = EVP_DigestFinal_ex(pEStack_c8,(uchar *)unaff_s6,(uint *)s_00);
    if (iVar2 == 0) goto LAB_00540560;
    EVP_MD_CTX_cleanup(pEStack_c8);
    pEVar3 = ctx->digest;
    if ((pEVar3->flags & 4) != 0) {
      local_80 = (uint ****)EVP_PKEY_size(pkey);
      sig = (EVP_PKEY *)0x0;
      pkey = (EVP_PKEY *)EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
      if (pkey == (EVP_PKEY *)0x0) goto LAB_00540560;
      iVar2 = EVP_PKEY_sign_init((EVP_PKEY_CTX *)pkey);
      if (iVar2 < 1) {
LAB_00540728:
        pEVar4 = (EVP_MD_CTX *)0x0;
        local_84 = s_00;
      }
      else {
        pkey_00 = (char *)0x1;
        s_00 = (uint *****)0xf8;
        sig = (EVP_PKEY *)0xffffffff;
        iVar2 = EVP_PKEY_CTX_ctrl((EVP_PKEY_CTX *)pkey,-1,0xf8,1,0,ctx->digest);
        if (iVar2 < 1) goto LAB_00540728;
        s_00 = &local_80;
        sig = (EVP_PKEY *)md;
        pkey_00 = (char *)unaff_s6;
        iVar2 = EVP_PKEY_sign((EVP_PKEY_CTX *)pkey,md,(size_t *)s_00,(uchar *)unaff_s6,
                              (size_t)local_84);
        if (iVar2 < 1) goto LAB_00540728;
        pEVar4 = (EVP_MD_CTX *)0x1;
        *s = (uint)local_80;
        local_84 = s_00;
      }
      goto LAB_00540568;
    }
    if ((pEVar3->required_pkey_type[0] == 0) ||
       ((iVar2 = pkey->type, pEVar3->required_pkey_type[0] != iVar2 &&
        ((pEVar3->required_pkey_type[1] == 0 ||
         ((iVar2 != pEVar3->required_pkey_type[1] &&
          ((pEVar3->required_pkey_type[2] == 0 ||
           ((iVar2 != pEVar3->required_pkey_type[2] &&
            ((pEVar3->required_pkey_type[3] == 0 || (pEVar3->required_pkey_type[3] != iVar2)))))))))
         ))))) {
      local_84 = (uint *****)&DAT_0000006e;
      iVar2 = 0x7f;
LAB_00540634:
      pkey_00 = "p_sign.c";
      sig = (EVP_PKEY *)&DAT_0000006b;
      ERR_put_error(6,0x6b,(int)local_84,"p_sign.c",iVar2);
      pEVar4 = (EVP_MD_CTX *)0x0;
    }
    else {
      if (pEVar3->sign == (_func_1083 *)0x0) {
        local_84 = (uint *****)&DAT_00000068;
        iVar2 = 0x85;
        goto LAB_00540634;
      }
      sig = unaff_s6;
      pkey_00 = (char *)md;
      pEVar4 = (EVP_MD_CTX *)
               (*pEVar3->sign)(pEVar3->type,(uchar *)unaff_s6,(uint)local_84,md,s,(pkey->pkey).ptr);
    }
  }
  if (local_24 == *(EVP_MD_CTX **)puStack_c4) {
    return (int)pEVar4;
  }
  uStack_ac = 0x540754;
  pEVar4 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_cc = *(int *)PTR___stack_chk_guard_006aabf0;
  pEStack_c0 = ctx;
  puStack_bc = s;
  pEStack_b8 = pkey;
  puStack_b4 = md;
  pEStack_b0 = unaff_s6;
  EVP_MD_CTX_init(&EStack_124);
  iVar2 = EVP_MD_CTX_copy_ex(&EStack_124,pEVar4);
  if (iVar2 == 0) {
LAB_005407fc:
    ctx_00 = (EVP_PKEY_CTX *)0x0;
    iVar2 = 0;
  }
  else {
    iVar2 = EVP_DigestFinal_ex(&EStack_124,auStack_10c,&uStack_128);
    if (iVar2 == 0) goto LAB_005407fc;
    EVP_MD_CTX_cleanup(&EStack_124);
    pEVar3 = pEVar4->digest;
    if ((pEVar3->flags & 4) == 0) {
      if ((pEVar3->required_pkey_type[0] == 0) ||
         ((iVar2 = *(int *)pkey_00, pEVar3->required_pkey_type[0] != iVar2 &&
          ((pEVar3->required_pkey_type[1] == 0 ||
           ((iVar2 != pEVar3->required_pkey_type[1] &&
            ((pEVar3->required_pkey_type[2] == 0 ||
             ((iVar2 != pEVar3->required_pkey_type[2] &&
              ((pEVar3->required_pkey_type[3] == 0 || (pEVar3->required_pkey_type[3] != iVar2)))))))
            ))))))) {
        ERR_put_error(6,0x6c,0x6e,"p_verify.c",0x6d);
        iVar2 = -1;
      }
      else if (pEVar3->verify == (_func_1084 *)0x0) {
        ERR_put_error(6,0x6c,0x69,"p_verify.c",0x72);
        iVar2 = 0;
      }
      else {
        iVar2 = (*pEVar3->verify)(pEVar3->type,auStack_10c,uStack_128,(uchar *)sig,(uint)local_84,
                                  ((_union_271 *)((int)pkey_00 + 0x14))->ptr);
      }
      goto LAB_00540818;
    }
    ctx_00 = EVP_PKEY_CTX_new((EVP_PKEY *)pkey_00,(ENGINE *)0x0);
    if (((ctx_00 == (EVP_PKEY_CTX *)0x0) || (iVar2 = EVP_PKEY_verify_init(ctx_00), iVar2 < 1)) ||
       (iVar2 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,1,0,pEVar4->digest), iVar2 < 1)) {
      iVar2 = -1;
    }
    else {
      iVar2 = EVP_PKEY_verify(ctx_00,(uchar *)sig,(size_t)local_84,auStack_10c,uStack_128);
    }
  }
  EVP_PKEY_CTX_free(ctx_00);
LAB_00540818:
  if (iStack_cc == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = iStack_cc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0xc) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar2 + 0xc) + 0x34),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00540a10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*UNRECOVERED_JUMPTABLE)();
    return iVar2;
  }
  return 0;
}

