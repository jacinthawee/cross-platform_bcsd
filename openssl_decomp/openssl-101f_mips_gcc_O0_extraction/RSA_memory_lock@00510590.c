
int RSA_memory_lock(RSA *r)

{
  undefined *puVar1;
  undefined *puVar2;
  uint *puVar3;
  BIGNUM **ppBVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  ulong *in_a1;
  int iVar9;
  uint in_a2;
  int iVar10;
  undefined4 uVar11;
  char *in_a3;
  BIGNUM *unaff_s0;
  BIGNUM *pBVar12;
  BIGNUM *unaff_s1;
  undefined4 unaff_s2;
  BIGNUM *unaff_s3;
  BIGNUM *unaff_s4;
  ulong *unaff_s6;
  BIGNUM ***unaff_s7;
  code *pcVar13;
  _func_1626 *p_Var14;
  undefined *puStack_c8;
  ulong *puStack_c0;
  int *piStack_bc;
  uint *puStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  int aiStack_ac [2];
  uint auStack_a4 [2];
  ulong *puStack_9c;
  int iStack_94;
  BIGNUM *pBStack_90;
  BIGNUM *pBStack_8c;
  undefined4 uStack_88;
  BIGNUM *pBStack_84;
  BIGNUM *pBStack_80;
  undefined *puStack_7c;
  ulong *puStack_78;
  BIGNUM ***pppBStack_74;
  RSA *pRStack_70;
  undefined4 uStack_6c;
  uint *local_58;
  RSA *pRStack_54;
  undefined *local_50;
  BIGNUM **local_44 [4];
  BIGNUM **local_34;
  BIGNUM **local_30;
  int local_2c;
  
  puStack_7c = PTR___stack_chk_guard_006aabf0;
  local_50 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (r->d == (BIGNUM *)0x0) {
    iVar5 = 1;
  }
  else {
    local_44[0] = &r->d;
    local_44[1] = &r->p;
    local_44[2] = &r->q;
    local_44[3] = &r->dmp1;
    local_34 = &r->dmq1;
    local_30 = &r->iqmp;
    unaff_s0 = (BIGNUM *)(CAST_S_table6 + 0x370);
    unaff_s4 = (BIGNUM *)
               (*(code *)PTR_CRYPTO_malloc_locked_006a9854)
                         ((r->d->top + r->p->top + r->q->top + r->dmp1->top + r->dmq1->top +
                           r->iqmp->top + 0x20) * 4,"rsa_lib.c",0x135);
    if (unaff_s4 == (BIGNUM *)0x0) {
      in_a3 = "rsa_lib.c";
      in_a2 = 0x41;
      in_a1 = (ulong *)0x82;
      local_58 = (uint *)0x137;
      (**(code **)(local_50 + -0x6eb0))(4);
      iVar5 = 0;
    }
    else {
      unaff_s6 = (ulong *)((int)&unaff_s4[1].dmax + 3);
      unaff_s7 = local_44;
      unaff_s3 = unaff_s4 + 6;
      unaff_s2 = 2;
      pBVar12 = unaff_s4;
      do {
        ppBVar4 = *unaff_s7;
        pcVar13 = *(code **)(local_50 + -0x52ec);
        unaff_s7 = unaff_s7 + 1;
        unaff_s1 = *ppBVar4;
        *ppBVar4 = pBVar12;
        in_a3 = (char *)unaff_s1->d;
        iVar10 = unaff_s1->top;
        iVar9 = unaff_s1->dmax;
        iVar8 = unaff_s1->neg;
        iVar5 = unaff_s1->flags;
        pBVar12->d = (ulong *)in_a3;
        pBVar12->top = iVar10;
        pBVar12->dmax = iVar9;
        pBVar12->neg = iVar8;
        pBVar12->flags = iVar5;
        unaff_s0 = pBVar12 + 1;
        pBVar12->flags = (int)&SUB_00000002;
        pBVar12->d = unaff_s6;
        in_a1 = unaff_s1->d;
        in_a2 = unaff_s1->top << 2;
        (*pcVar13)(unaff_s6);
        unaff_s6 = unaff_s6 + unaff_s1->top;
        BN_clear_free(unaff_s1);
        pBVar12 = unaff_s0;
      } while (unaff_s0 != unaff_s3);
      iVar5 = 1;
      r->bignum_data = (char *)unaff_s4;
      r->flags = r->flags & 0xfffffff9;
    }
  }
  if (local_2c == *(int *)puStack_7c) {
    return iVar5;
  }
  uStack_6c = 0x5107cc;
  iVar5 = local_2c;
  (**(code **)(local_50 + -0x5328))();
  puVar3 = local_58;
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puStack_c8 = &_gp;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  pBStack_90 = unaff_s0;
  pBStack_8c = unaff_s1;
  uStack_88 = unaff_s2;
  pBStack_84 = unaff_s3;
  pBStack_80 = unaff_s4;
  puStack_78 = unaff_s6;
  pppBStack_74 = unaff_s7;
  pRStack_70 = r;
  if (((pRStack_54->flags & 0x40U) != 0) &&
     (p_Var14 = pRStack_54->meth->rsa_sign, p_Var14 != (_func_1626 *)0x0)) {
    iVar5 = (*p_Var14)(iVar5,(uchar *)in_a1,in_a2,(uchar *)in_a3,local_58,pRStack_54);
    goto LAB_00510860;
  }
  if (iVar5 == 0x72) {
    if (in_a2 == 0x24) {
      iVar5 = RSA_size(pRStack_54);
      if (0x2e < iVar5) {
        uVar6 = RSA_private_encrypt(0x24,(uchar *)in_a1,(uchar *)in_a3,pRStack_54,1);
        iVar5 = 0;
        if (0 < (int)uVar6) {
          *puVar3 = uVar6;
          iVar5 = 1;
        }
        goto LAB_00510860;
      }
      goto LAB_00510a28;
    }
    uVar11 = 0x83;
    uVar7 = 0x60;
    pcVar13 = (code *)PTR_ERR_put_error_006a9030;
  }
  else {
    piStack_bc = aiStack_ac;
    aiStack_ac[0] = (*(code *)PTR_OBJ_nid2obj_006a8240)(iVar5);
    puVar1 = PTR_i2d_X509_SIG_006a9858;
    if (*piStack_bc == 0) {
      uVar11 = 0x75;
      uVar7 = 0x6a;
      pcVar13 = (code *)PTR_ERR_put_error_006a9030;
    }
    else {
      iVar5 = *(int *)(*piStack_bc + 0xc);
      if (iVar5 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(4,0x75,0x74,"rsa_sign.c",0x6f);
        goto LAB_00510860;
      }
      uStack_b0 = 0;
      auStack_a4[0] = in_a2;
      piStack_bc[1] = (int)&uStack_b4;
      uStack_b4 = 5;
      puStack_b8 = auStack_a4;
      puStack_9c = in_a1;
      iVar5 = (*(code *)puVar1)(&piStack_bc,0);
      iVar8 = RSA_size(pRStack_54);
      if (iVar5 < iVar8 + -10) {
        in_a2 = iVar8 + 1;
        in_a1 = (ulong *)(**(code **)(puStack_c8 + -0x7dd8))(in_a2,"rsa_sign.c",0x83);
        if (in_a1 != (ulong *)0x0) {
          puStack_c0 = in_a1;
          (**(code **)(puStack_c8 + -0x6688))(&piStack_bc,&puStack_c0);
          uVar6 = RSA_private_encrypt(iVar5,(uchar *)in_a1,(uchar *)in_a3,pRStack_54,1);
          if ((int)uVar6 < 1) goto LAB_00510ae4;
          iVar5 = 1;
          *puVar3 = uVar6;
          goto LAB_005109a4;
        }
        iVar5 = 0;
        (**(code **)(puStack_c8 + -0x6eb0))(4,0x75,0x41,"rsa_sign.c",0x86);
        goto LAB_00510860;
      }
LAB_00510a28:
      uVar11 = 0x70;
      uVar7 = 0x7f;
      pcVar13 = *(code **)(puStack_c8 + -0x6eb0);
    }
  }
  iVar5 = 0;
  (*pcVar13)(4,0x75,uVar11,"rsa_sign.c",uVar7);
LAB_00510860:
  while( true ) {
    if (iStack_94 == *(int *)puVar2) break;
    (**(code **)(puStack_c8 + -0x5328))();
LAB_00510ae4:
    iVar5 = 0;
LAB_005109a4:
    (**(code **)(puStack_c8 + -0x7d6c))(in_a1,in_a2);
    (**(code **)(puStack_c8 + -0x7f58))(in_a1);
  }
  return iVar5;
}

