
int EVP_DigestSignInit(EVP_MD_CTX *ctx,EVP_PKEY_CTX **pctx,EVP_MD *type,ENGINE *e,EVP_PKEY *pkey)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  EVP_MD_CTX *pEVar5;
  size_t tbslen;
  int *piVar6;
  EVP_PKEY_CTX *pEVar7;
  EVP_MD_CTX *in;
  EVP_MD *pnid;
  EVP_MD *siglen;
  code *pcVar8;
  size_t sStack_110;
  EVP_MD_CTX EStack_10c;
  uchar auStack_f4 [64];
  int iStack_b4;
  EVP_MD *pEStack_ac;
  EVP_MD *pEStack_a8;
  undefined *puStack_a4;
  EVP_MD *pEStack_a0;
  char *pcStack_9c;
  EVP_PKEY *pEStack_98;
  code *pcStack_94;
  int iStack_70;
  EVP_MD_CTX *pEStack_6c;
  EVP_MD_CTX *pEStack_64;
  EVP_MD *pEStack_60;
  _func_1079 *p_Stack_5c;
  EVP_PKEY_CTX **ppEStack_58;
  ENGINE *pEStack_54;
  EVP_PKEY *pEStack_50;
  code *pcStack_4c;
  EVP_PKEY *in_stack_ffffffc8;
  _func_1085 *local_28;
  EVP_MD *local_24;
  
  p_Stack_5c = (_func_1079 *)PTR___stack_chk_guard_006aabf0;
  piVar6 = (int *)ctx->pctx;
  local_24 = *(EVP_MD **)PTR___stack_chk_guard_006aabf0;
  pEStack_a0 = (EVP_MD *)pctx;
  pEStack_a8 = type;
  pcStack_9c = (char *)e;
  pEStack_98 = in_stack_ffffffc8;
  if (piVar6 == (int *)0x0) {
    pEStack_a0 = (EVP_MD *)e;
    piVar6 = (int *)EVP_PKEY_CTX_new(pkey,e);
    ctx->pctx = (EVP_PKEY_CTX *)piVar6;
    pEStack_98 = in_stack_ffffffc8;
    if (piVar6 != (int *)0x0) goto LAB_00549f58;
    uVar3 = 0;
  }
  else {
LAB_00549f58:
    if (type == (EVP_MD *)0x0) {
      pEStack_a0 = (EVP_MD *)&local_28;
      iVar2 = EVP_PKEY_get_default_digest_nid(pkey,(int *)pEStack_a0);
      if (0 < iVar2) {
        pcVar4 = (char *)(*(code *)PTR_OBJ_nid2sn_006a819c)(local_28);
        type = EVP_get_digestbyname(pcVar4);
        if (type != (EVP_MD *)0x0) {
          piVar6 = (int *)ctx->pctx;
          goto LAB_00549f60;
        }
      }
      pEStack_a8 = (EVP_MD *)&DAT_0000009e;
      pcStack_9c = "m_sigver.c";
      pEStack_98 = (EVP_PKEY *)0x54;
      pEStack_a0 = (EVP_MD *)0xa1;
      ERR_put_error(6,0xa1,0x9e,"m_sigver.c",0x54);
    }
    else {
LAB_00549f60:
      if (*(code **)(*piVar6 + 0x3c) == (code *)0x0) {
        iVar2 = EVP_PKEY_sign_init((EVP_PKEY_CTX *)piVar6);
        if (0 < iVar2) {
          pEVar7 = ctx->pctx;
          goto LAB_00549f8c;
        }
      }
      else {
        pEStack_a0 = (EVP_MD *)ctx;
        iVar2 = (**(code **)(*piVar6 + 0x3c))();
        if (0 < iVar2) {
          pEVar7 = ctx->pctx;
          *(undefined4 *)(pEVar7 + 0x10) = 0x40;
LAB_00549f8c:
          pcStack_9c = (char *)0x1;
          pEStack_a8 = (EVP_MD *)0xf8;
          pEStack_a0 = (EVP_MD *)0xffffffff;
          pEStack_98 = (EVP_PKEY *)0x0;
          iVar2 = EVP_PKEY_CTX_ctrl(pEVar7,-1,0xf8,1,0,type);
          if (0 < iVar2) {
            if (pctx != (EVP_PKEY_CTX **)0x0) {
              *pctx = ctx->pctx;
            }
            pEStack_a0 = type;
            pEStack_a8 = (EVP_MD *)e;
            iVar2 = EVP_DigestInit_ex(ctx,type,e);
            uVar3 = (uint)(iVar2 != 0);
            goto LAB_00549fd8;
          }
        }
      }
    }
    uVar3 = 0;
  }
LAB_00549fd8:
  if (local_24 == *(EVP_MD **)p_Stack_5c) {
    return uVar3;
  }
  pcStack_4c = EVP_DigestVerifyInit;
  pEStack_ac = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_a4 = PTR___stack_chk_guard_006aabf0;
  piVar6 = (int *)pEStack_ac->init;
  pEStack_50 = pkey;
  pEStack_6c = *(EVP_MD_CTX **)PTR___stack_chk_guard_006aabf0;
  pnid = pEStack_a0;
  siglen = pEStack_a8;
  pEStack_64 = ctx;
  pEStack_60 = type;
  ppEStack_58 = pctx;
  pEStack_54 = e;
  if (piVar6 == (int *)0x0) {
    pnid = (EVP_MD *)pcStack_9c;
    piVar6 = (int *)EVP_PKEY_CTX_new(pEStack_98,(ENGINE *)pcStack_9c);
    pEStack_ac->init = (_func_1078 *)piVar6;
    if (piVar6 == (int *)0x0) {
      uVar3 = 0;
      goto LAB_0054a1a0;
    }
  }
  if (pEStack_a8 == (EVP_MD *)0x0) {
    pnid = (EVP_MD *)&iStack_70;
    iVar2 = EVP_PKEY_get_default_digest_nid(pEStack_98,(int *)pnid);
    if (0 < iVar2) {
      pcVar4 = (char *)(*(code *)PTR_OBJ_nid2sn_006a819c)(iStack_70);
      pEStack_a8 = EVP_get_digestbyname(pcVar4);
      if (pEStack_a8 != (EVP_MD *)0x0) {
        piVar6 = (int *)pEStack_ac->init;
        goto LAB_0054a128;
      }
    }
    siglen = (EVP_MD *)&DAT_0000009e;
    pnid = (EVP_MD *)0xa1;
    ERR_put_error(6,0xa1,0x9e,"m_sigver.c",0x54);
  }
  else {
LAB_0054a128:
    if (*(code **)(*piVar6 + 0x44) == (code *)0x0) {
      iVar2 = EVP_PKEY_verify_init((EVP_PKEY_CTX *)piVar6);
      if (0 < iVar2) {
        pEVar7 = (EVP_PKEY_CTX *)pEStack_ac->init;
        goto LAB_0054a154;
      }
    }
    else {
      pnid = pEStack_ac;
      iVar2 = (**(code **)(*piVar6 + 0x44))();
      if (0 < iVar2) {
        pEVar7 = (EVP_PKEY_CTX *)pEStack_ac->init;
        *(undefined4 *)(pEVar7 + 0x10) = 0x80;
LAB_0054a154:
        siglen = (EVP_MD *)0xf8;
        pnid = (EVP_MD *)0xffffffff;
        iVar2 = EVP_PKEY_CTX_ctrl(pEVar7,-1,0xf8,1,0,pEStack_a8);
        if (0 < iVar2) {
          if (pEStack_a0 != (EVP_MD *)0x0) {
            pEStack_a0->type = (int)pEStack_ac->init;
          }
          pnid = pEStack_a8;
          siglen = (EVP_MD *)pcStack_9c;
          iVar2 = EVP_DigestInit_ex((EVP_MD_CTX *)pEStack_ac,pEStack_a8,(ENGINE *)pcStack_9c);
          uVar3 = (uint)(iVar2 != 0);
          goto LAB_0054a1a0;
        }
      }
    }
  }
  uVar3 = 0;
LAB_0054a1a0:
  if (pEStack_6c == *(EVP_MD_CTX **)puStack_a4) {
    return uVar3;
  }
  pcStack_94 = EVP_DigestSignFinal;
  in = pEStack_6c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar8 = *(code **)(*(int *)in->pctx + 0x40);
  if (pcVar8 == (code *)0x0) {
    if (pnid != (EVP_MD *)0x0) goto LAB_0054a3f0;
    tbslen = EVP_MD_size(in->digest);
    if (-1 < (int)tbslen) {
      iVar2 = EVP_PKEY_sign(in->pctx,(uchar *)0x0,(size_t *)siglen,(uchar *)0x0,tbslen);
      pEVar5 = (EVP_MD_CTX *)(uint)(0 < iVar2);
      goto LAB_0054a320;
    }
  }
  else {
    if (pnid == (EVP_MD *)0x0) {
      iVar2 = (*pcVar8)();
      pEVar5 = (EVP_MD_CTX *)(uint)(0 < iVar2);
      goto LAB_0054a320;
    }
    EVP_MD_CTX_init(&EStack_10c);
    iVar2 = EVP_MD_CTX_copy_ex(&EStack_10c,in);
    if (iVar2 != 0) {
      pEVar5 = (EVP_MD_CTX *)
               (**(code **)(*(int *)EStack_10c.pctx + 0x40))
                         (EStack_10c.pctx,pnid,siglen,&EStack_10c);
      EVP_MD_CTX_cleanup(&EStack_10c);
      in = pEVar5;
      goto LAB_0054a320;
    }
  }
  do {
    pEVar5 = (EVP_MD_CTX *)0x0;
LAB_0054a320:
    while( true ) {
      if (iStack_b4 == *(int *)puVar1) {
        return (int)pEVar5;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0054a3f0:
      EVP_MD_CTX_init(&EStack_10c);
      iVar2 = EVP_MD_CTX_copy_ex(&EStack_10c,in);
      if (iVar2 == 0) break;
      iVar2 = EVP_DigestFinal_ex(&EStack_10c,auStack_f4,&sStack_110);
      EVP_MD_CTX_cleanup(&EStack_10c);
      if (iVar2 == 0) break;
      iVar2 = EVP_PKEY_sign(in->pctx,(uchar *)pnid,(size_t *)siglen,auStack_f4,sStack_110);
      if (iVar2 < 1) break;
      pEVar5 = (EVP_MD_CTX *)0x1;
    }
  } while( true );
}

