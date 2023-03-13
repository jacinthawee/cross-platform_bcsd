
int EVP_DigestVerifyInit(EVP_MD_CTX *ctx,EVP_PKEY_CTX **pctx,EVP_MD *type,ENGINE *e,EVP_PKEY *pkey)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  char *name;
  EVP_MD_CTX *pEVar4;
  size_t tbslen;
  int *ctx_00;
  EVP_PKEY_CTX *ctx_01;
  EVP_MD_CTX *in;
  EVP_MD *pnid;
  EVP_MD *siglen;
  code *pcVar5;
  size_t sStack_c8;
  EVP_MD_CTX EStack_c4;
  uchar auStack_ac [64];
  int iStack_6c;
  EVP_MD_CTX *pEStack_64;
  EVP_MD *pEStack_60;
  undefined *puStack_5c;
  EVP_PKEY_CTX **ppEStack_58;
  ENGINE *pEStack_54;
  EVP_PKEY *pEStack_50;
  code *pcStack_4c;
  int local_28;
  EVP_MD_CTX *local_24;
  
  puStack_5c = PTR___stack_chk_guard_006a9ae8;
  ctx_00 = (int *)ctx->pctx;
  local_24 = *(EVP_MD_CTX **)PTR___stack_chk_guard_006a9ae8;
  pnid = (EVP_MD *)pctx;
  siglen = type;
  if (ctx_00 == (int *)0x0) {
    pnid = (EVP_MD *)e;
    ctx_00 = (int *)EVP_PKEY_CTX_new(pkey,e);
    ctx->pctx = (EVP_PKEY_CTX *)ctx_00;
    if (ctx_00 == (int *)0x0) {
      uVar3 = 0;
      goto LAB_00546f10;
    }
  }
  if (type == (EVP_MD *)0x0) {
    pnid = (EVP_MD *)&local_28;
    iVar2 = EVP_PKEY_get_default_digest_nid(pkey,(int *)pnid);
    if (0 < iVar2) {
      name = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)(local_28);
      type = EVP_get_digestbyname(name);
      if (type != (EVP_MD *)0x0) {
        ctx_00 = (int *)ctx->pctx;
        goto LAB_00546e98;
      }
    }
    siglen = (EVP_MD *)&DAT_0000009e;
    pnid = (EVP_MD *)0xa1;
    ERR_put_error(6,0xa1,0x9e,"m_sigver.c",0x53);
  }
  else {
LAB_00546e98:
    if (*(code **)(*ctx_00 + 0x44) == (code *)0x0) {
      iVar2 = EVP_PKEY_verify_init((EVP_PKEY_CTX *)ctx_00);
      if (0 < iVar2) {
        ctx_01 = ctx->pctx;
        goto LAB_00546ec4;
      }
    }
    else {
      pnid = (EVP_MD *)ctx;
      iVar2 = (**(code **)(*ctx_00 + 0x44))();
      if (0 < iVar2) {
        ctx_01 = ctx->pctx;
        *(undefined4 *)(ctx_01 + 0x10) = 0x80;
LAB_00546ec4:
        siglen = (EVP_MD *)0xf8;
        pnid = (EVP_MD *)0xffffffff;
        iVar2 = EVP_PKEY_CTX_ctrl(ctx_01,-1,0xf8,1,0,type);
        if (0 < iVar2) {
          if (pctx != (EVP_PKEY_CTX **)0x0) {
            *pctx = ctx->pctx;
          }
          pnid = type;
          siglen = (EVP_MD *)e;
          iVar2 = EVP_DigestInit_ex(ctx,type,e);
          uVar3 = (uint)(iVar2 != 0);
          goto LAB_00546f10;
        }
      }
    }
  }
  uVar3 = 0;
LAB_00546f10:
  if (local_24 == *(EVP_MD_CTX **)puStack_5c) {
    return uVar3;
  }
  pcStack_4c = EVP_DigestSignFinal;
  in = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pEStack_50 = pkey;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar5 = *(code **)(*(int *)in->pctx + 0x40);
  pEStack_64 = ctx;
  pEStack_60 = type;
  ppEStack_58 = pctx;
  pEStack_54 = e;
  if (pcVar5 == (code *)0x0) {
    if (pnid != (EVP_MD *)0x0) goto LAB_00547160;
    tbslen = EVP_MD_size(in->digest);
    if (-1 < (int)tbslen) {
      iVar2 = EVP_PKEY_sign(in->pctx,(uchar *)0x0,(size_t *)siglen,(uchar *)0x0,tbslen);
      pEVar4 = (EVP_MD_CTX *)(uint)(0 < iVar2);
      goto LAB_00547090;
    }
  }
  else {
    if (pnid == (EVP_MD *)0x0) {
      iVar2 = (*pcVar5)();
      pEVar4 = (EVP_MD_CTX *)(uint)(0 < iVar2);
      goto LAB_00547090;
    }
    EVP_MD_CTX_init(&EStack_c4);
    iVar2 = EVP_MD_CTX_copy_ex(&EStack_c4,in);
    if (iVar2 != 0) {
      pEVar4 = (EVP_MD_CTX *)
               (**(code **)(*(int *)EStack_c4.pctx + 0x40))(EStack_c4.pctx,pnid,siglen,&EStack_c4);
      EVP_MD_CTX_cleanup(&EStack_c4);
      in = pEVar4;
      goto LAB_00547090;
    }
  }
  do {
    pEVar4 = (EVP_MD_CTX *)0x0;
LAB_00547090:
    while( true ) {
      if (iStack_6c == *(int *)puVar1) {
        return (int)pEVar4;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00547160:
      EVP_MD_CTX_init(&EStack_c4);
      iVar2 = EVP_MD_CTX_copy_ex(&EStack_c4,in);
      if (iVar2 == 0) break;
      iVar2 = EVP_DigestFinal_ex(&EStack_c4,auStack_ac,&sStack_c8);
      EVP_MD_CTX_cleanup(&EStack_c4);
      if (iVar2 == 0) break;
      iVar2 = EVP_PKEY_sign(in->pctx,(uchar *)pnid,(size_t *)siglen,auStack_ac,sStack_c8);
      if (iVar2 < 1) break;
      pEVar4 = (EVP_MD_CTX *)0x1;
    }
  } while( true );
}

