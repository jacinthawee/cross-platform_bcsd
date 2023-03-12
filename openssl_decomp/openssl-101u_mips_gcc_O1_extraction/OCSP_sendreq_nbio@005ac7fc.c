
int OCSP_sendreq_nbio(OCSP_RESPONSE **presp,OCSP_REQ_CTX *rctx)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  uint3 uVar5;
  ASN1_OBJECT **ppAVar6;
  undefined *puVar7;
  undefined *puVar8;
  uint uVar9;
  uint uVar10;
  OCSP_RESPONSE *pOVar11;
  OCSP_SIGNATURE *pOVar12;
  int iVar13;
  OCSP_CERTID *pOVar14;
  int iVar15;
  undefined4 uVar16;
  ASN1_OBJECT *pAVar17;
  ASN1_TYPE *pAVar18;
  ASN1_INTEGER *pAVar19;
  undefined4 *puVar20;
  char *path;
  ASN1_OBJECT *pAVar21;
  ASN1_OBJECT *in_a2;
  ASN1_OBJECT *pAVar22;
  undefined4 uVar23;
  char *pcVar24;
  ASN1_OBJECT *pAVar25;
  X509_ALGOR *pXVar26;
  ASN1_OBJECT *unaff_s6;
  ASN1_OBJECT *unaff_s7;
  code *pcVar27;
  undefined4 uStack_1b0;
  ASN1_OBJECT aAStack_1ac [2];
  undefined4 *puStack_16c;
  OCSP_CERTID *pOStack_164;
  int iStack_160;
  undefined *puStack_15c;
  ASN1_OBJECT *pAStack_158;
  undefined4 uStack_154;
  int iStack_150;
  ASN1_OBJECT **ppAStack_14c;
  ASN1_OBJECT *pAStack_148;
  code *pcStack_144;
  int iStack_130;
  undefined4 uStack_12c;
  undefined *puStack_128;
  undefined auStack_120 [68];
  int iStack_dc;
  ASN1_OBJECT *pAStack_d4;
  ASN1_OBJECT *pAStack_d0;
  undefined4 uStack_cc;
  OCSP_SIGNATURE **ppOStack_c8;
  BIO *pBStack_c4;
  undefined *puStack_c0;
  ASN1_OBJECT *pAStack_bc;
  ASN1_OBJECT *pAStack_b8;
  undefined4 uStack_b4;
  undefined *puStack_a0;
  OCSP_SIGNATURE *pOStack_98;
  int iStack_94;
  ASN1_OBJECT *pAStack_8c;
  ASN1_OBJECT *pAStack_88;
  undefined4 uStack_84;
  OCSP_SIGNATURE **ppOStack_80;
  undefined *puStack_7c;
  OCSP_RESPONSE **ppOStack_78;
  code *pcStack_74;
  ASN1_OBJECT *local_60;
  undefined *local_58;
  uint local_4c;
  ASN1_OBJECT *local_48;
  ASN1_OBJECT *local_44;
  ASN1_OBJECT *local_40;
  ASN1_OBJECT *local_3c;
  ASN1_OBJECT *local_34;
  OCSP_SIGNATURE *local_30;
  BIO *local_2c;
  
  puStack_7c = PTR___stack_chk_guard_006a9ae8;
  uVar9 = *(uint *)rctx;
  uStack_cc = 4;
  pAStack_d4 = (ASN1_OBJECT *)&local_34;
  ppOStack_c8 = &local_30;
  local_58 = &_gp;
  local_4c = 0x19001;
  local_2c = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  path = (char *)rctx;
LAB_005ac864:
  pAVar25 = (ASN1_OBJECT *)(uVar9 & 0x1000);
  pcVar27 = *(code **)(local_58 + -0x7920);
  if (pAVar25 == (ASN1_OBJECT *)0x0) goto LAB_005ac97c;
  pcVar27 = *(code **)(local_58 + -0x7fc8);
  if (uVar9 != 4) {
    do {
      if ((int)uVar9 < 5) {
        if ((int)uVar9 < 1) {
LAB_005ac89c:
          pAVar25 = (ASN1_OBJECT *)0x0;
          goto LAB_005ac8a0;
        }
        if (2 < (int)uVar9) goto LAB_005aca00;
        unaff_s6 = (ASN1_OBJECT *)&DAT_0000000d;
        goto LAB_005acc10;
      }
      if (uVar9 != 0x1007) {
        if (uVar9 == 0x1008) {
          pAVar25 = (ASN1_OBJECT *)0x1;
        }
        else {
          if (uVar9 != 0x1006) goto LAB_005ac89c;
          iVar13 = (**(code **)(local_58 + -0x7fc8))(*(undefined4 *)(rctx + 0x10),3,0,pAStack_d4);
          in_a2 = *(ASN1_OBJECT **)(rctx + 0x14);
          path = (char *)((int)local_34 + (iVar13 - (int)in_a2));
          iVar13 = (**(code **)(local_58 + -0x7fcc))(*(undefined4 *)(rctx + 0xc));
          if (0 < iVar13) {
            iVar15 = *(int *)(rctx + 0x14);
            *(int *)(rctx + 0x14) = iVar15 - iVar13;
            pAVar22 = local_34;
            if (iVar15 - iVar13 == 0) {
              pcVar27 = *(code **)(local_58 + -0x7fc8);
              *(undefined4 *)rctx = 0x1007;
              (*pcVar27)(*(undefined4 *)(rctx + 0x10),1,0,0);
              goto LAB_005ac94c;
            }
            goto LAB_005ac9e8;
          }
LAB_005aced4:
          path = &DAT_00000008;
          pAVar25 = (ASN1_OBJECT *)0xffffffff;
          iVar13 = (**(code **)(local_58 + -0x7578))(*(undefined4 *)(rctx + 0xc));
          pAVar22 = local_34;
          if (iVar13 == 0) goto LAB_005acbf8;
        }
        goto LAB_005ac8a0;
      }
LAB_005ac94c:
      in_a2 = (ASN1_OBJECT *)0x0;
      iVar13 = (**(code **)(local_58 + -0x7fc8))(*(undefined4 *)(rctx + 0xc),0xb,0,0);
      if (iVar13 < 1) goto LAB_005aced4;
      pAVar25 = (ASN1_OBJECT *)0x0;
      *(undefined4 *)rctx = 1;
      pcVar27 = *(code **)(local_58 + -0x7920);
LAB_005ac97c:
      in_a2 = *(ASN1_OBJECT **)(rctx + 8);
      unaff_s6 = (ASN1_OBJECT *)(*pcVar27)(*(undefined4 *)(rctx + 0xc),*(undefined4 *)(rctx + 4));
      if ((int)unaff_s6 < 1) {
        path = &DAT_00000008;
        iVar13 = (**(code **)(local_58 + -0x7578))(*(undefined4 *)(rctx + 0xc));
        pAVar25 = (ASN1_OBJECT *)-(uint)(iVar13 != 0);
        goto LAB_005ac8a0;
      }
      path = *(char **)(rctx + 4);
      in_a2 = unaff_s6;
      pAVar22 = (ASN1_OBJECT *)(**(code **)(local_58 + -0x7fcc))(*(undefined4 *)(rctx + 0x10));
      if (unaff_s6 != pAVar22) goto LAB_005ac8a0;
      uVar9 = *(uint *)rctx;
    } while (uVar9 != 4);
    goto LAB_005ac9c0;
  }
  goto LAB_005ac9c4;
LAB_005acc10:
  pcVar27 = *(code **)(local_58 + -0x7fc8);
  do {
    in_a2 = (ASN1_OBJECT *)0x0;
    path = (char *)0x3;
    unaff_s7 = (ASN1_OBJECT *)(*pcVar27)(*(undefined4 *)(rctx + 0x10),3,0,pAStack_d4);
    if ((int)unaff_s7 < 1) {
LAB_005acd98:
      pAVar22 = local_34;
      if (*(int *)(rctx + 8) <= (int)unaff_s7) goto LAB_005acbf8;
      uVar9 = *(uint *)rctx;
      goto LAB_005ac864;
    }
    path = &DAT_0000000a;
    in_a2 = unaff_s7;
    iVar13 = (**(code **)(local_58 + -0x53fc))(local_34);
    if (iVar13 == 0) goto LAB_005acd98;
    in_a2 = *(ASN1_OBJECT **)(rctx + 8);
    path = *(char **)(rctx + 4);
    iVar13 = (**(code **)(local_58 + -0x790c))(*(undefined4 *)(rctx + 0x10));
    if (iVar13 < 1) {
      path = &DAT_00000008;
      iVar13 = (**(code **)(local_58 + -0x7578))(*(undefined4 *)(rctx + 0x10));
      pAVar22 = local_34;
      if (iVar13 == 0) goto LAB_005acbf8;
      uVar9 = *(uint *)rctx;
      goto LAB_005ac864;
    }
    pAVar22 = local_34;
    if (iVar13 == *(int *)(rctx + 8)) goto LAB_005acbf8;
    if (*(int *)rctx == 1) break;
    cVar2 = *(char *)&(*(ASN1_OBJECT **)(rctx + 4))->sn;
    local_34 = *(ASN1_OBJECT **)(rctx + 4);
    while( true ) {
      if (cVar2 == '\0') {
        *(undefined4 *)rctx = 3;
        goto LAB_005aca00;
      }
      pAVar25 = (ASN1_OBJECT *)((int)&local_34->sn + 1);
      if ((cVar2 != '\r') && (pcVar27 = *(code **)(local_58 + -0x7fc8), cVar2 != '\n')) break;
      cVar2 = *(char *)&pAVar25->sn;
      local_34 = pAVar25;
    }
  } while( true );
  pAVar25 = *(ASN1_OBJECT **)(rctx + 4);
  local_48 = (ASN1_OBJECT *)(int)*(char *)&pAVar25->sn;
  if (local_48 == (ASN1_OBJECT *)0x0) {
LAB_005acd24:
    pcVar27 = *(code **)(local_58 + -0x6eac);
    local_60 = (ASN1_OBJECT *)&DAT_000000ca;
    unaff_s7 = pAVar25;
LAB_005acd68:
    in_a2 = (ASN1_OBJECT *)&DAT_00000073;
    path = &DAT_00000076;
    pAVar25 = (ASN1_OBJECT *)0x0;
    (*pcVar27)(0x27,0x76,0x73,"ocsp_ht.c");
    *(undefined4 *)rctx = 0x1000;
    goto LAB_005ac8a0;
  }
  pAVar21 = (ASN1_OBJECT *)(**(code **)(local_58 + -0x54a8))();
  pAVar17 = (ASN1_OBJECT *)pAVar21->sn;
  pAVar22 = local_48;
  while (uVar9 = (uint)pAVar22 & 0xff, (*(ushort *)((int)&pAVar17->sn + uVar9 * 2) & 0x20) == 0) {
    pAVar25 = (ASN1_OBJECT *)((int)&pAVar25->sn + 1);
    pAVar22 = (ASN1_OBJECT *)(int)*(char *)&pAVar25->sn;
    if (pAVar22 == (ASN1_OBJECT *)0x0) goto LAB_005acd24;
  }
  while (unaff_s7 = (ASN1_OBJECT *)((int)&pAVar25->sn + 1), pAVar22 = pAVar25,
        (*(ushort *)((int)&pAVar17->sn + uVar9 * 2) & 0x20) != 0) {
    uVar9 = (int)*(char *)&unaff_s7->sn & 0xff;
    pAVar25 = unaff_s7;
    if ((int)*(char *)&unaff_s7->sn == 0) {
      pcVar27 = *(code **)(local_58 + -0x6eac);
      local_60 = (ASN1_OBJECT *)0xd3;
      goto LAB_005acd68;
    }
  }
  while (pcVar27 = *(code **)(local_58 + -0x53b4), unaff_s7 = pAVar25,
        (*(ushort *)((int)&pAVar17->sn + uVar9 * 2) & 0x20) == 0) {
    pAVar22 = (ASN1_OBJECT *)((int)&pAVar22->sn + 1);
    uVar9 = (int)*(char *)&pAVar22->sn & 0xff;
    if ((int)*(char *)&pAVar22->sn == 0) {
      pcVar27 = *(code **)(local_58 + -0x6eac);
      local_60 = (ASN1_OBJECT *)&DAT_000000dc;
      goto LAB_005acd68;
    }
  }
  in_a2 = (ASN1_OBJECT *)&DAT_0000000a;
  *(undefined *)&pAVar22->sn = 0;
  local_48 = pAVar22;
  local_44 = pAVar21;
  path = (char *)(*pcVar27)(pAVar25,ppOStack_c8);
  pAVar22 = local_34;
  if (*(char *)&local_30->signatureAlgorithm != '\0') goto LAB_005acbf8;
  uVar9 = (uint)*(char *)((int)&local_48->sn + 1);
  local_48 = (ASN1_OBJECT *)((int)&local_48->sn + 1);
  if (uVar9 != 0) {
    ppAVar6 = (ASN1_OBJECT **)&local_44->sn;
    pAVar22 = local_48;
LAB_005acafc:
    local_48 = (ASN1_OBJECT *)((int)&pAVar22->sn + 1);
    if ((*(ushort *)((int)&(*ppAVar6)->sn + (uVar9 & 0xff) * 2) & 0x20) != 0) goto LAB_005acaf0;
    local_40 = local_44;
    local_48 = pAVar22;
    local_44 = (ASN1_OBJECT *)path;
    local_3c = *ppAVar6;
    iVar13 = (**(code **)(local_58 + -0x53bc))(pAVar22);
    local_30 = (OCSP_SIGNATURE *)((int)local_48 + iVar13 + -1);
    pAVar22 = local_3c;
    while (path = (char *)local_44,
          (*(ushort *)((int)&pAVar22->sn + (uint)*(byte *)&local_30->signatureAlgorithm * 2) & 0x20)
          != 0) {
      *(undefined *)&local_30->signatureAlgorithm = 0;
      pAVar22 = (ASN1_OBJECT *)local_40->sn;
      local_30 = (OCSP_SIGNATURE *)((int)&local_30[-1].certs + 3);
    }
  }
LAB_005acb8c:
  if ((ASN1_OBJECT *)path != (ASN1_OBJECT *)&DAT_000000c8) {
    local_60 = (ASN1_OBJECT *)0xf7;
    (**(code **)(local_58 + -0x6eac))(0x27,0x76,0x72,"ocsp_ht.c");
    in_a2 = pAVar25;
    if (*(char *)&local_48->sn == '\0') {
      path = "Code=";
      (**(code **)(local_58 + -0x6ca4))(2);
      pAVar22 = local_34;
    }
    else {
      local_60 = local_48;
      path = "Code=";
      (**(code **)(local_58 + -0x6ca4))(4,"Code=",pAVar25,",Reason=");
      pAVar22 = local_34;
    }
    goto LAB_005acbf8;
  }
  *(undefined4 *)rctx = 2;
  goto LAB_005acc10;
LAB_005acaf0:
  uVar9 = (uint)*(char *)&local_48->sn;
  pAVar22 = local_48;
  if (uVar9 == 0) goto LAB_005acb8c;
  goto LAB_005acafc;
LAB_005aca00:
  in_a2 = (ASN1_OBJECT *)0x0;
  path = (char *)0x3;
  iVar13 = (**(code **)(local_58 + -0x7fc8))(*(undefined4 *)(rctx + 0x10),3,0,pAStack_d4);
  pAVar22 = local_34;
  if (iVar13 < 2) {
LAB_005ac9e8:
    local_34 = pAVar22;
    uVar9 = *(uint *)rctx;
    goto LAB_005ac864;
  }
  pAVar22 = (ASN1_OBJECT *)((int)&local_34->sn + 1);
  path = (char *)(uint)*(byte *)&local_34->sn;
  if ((ASN1_OBJECT *)path != (ASN1_OBJECT *)&DAT_00000030) goto LAB_005acbf8;
  bVar1 = *(byte *)((int)&local_34->sn + 1);
  path = (char *)(int)(char)bVar1;
  if ((int)path < 0) {
    uVar9 = bVar1 & 0x7f;
    if (iVar13 < 6) goto LAB_005ac9e8;
    if (3 < uVar9 - 1) goto LAB_005acbf8;
    *(undefined4 *)(rctx + 0x14) = 0;
    bVar1 = *(byte *)((int)&local_34->sn + 2);
    uVar10 = (uint)bVar1;
    pAVar25 = (ASN1_OBJECT *)((int)&local_34->sn + 3);
    if (uVar9 != 1) {
      *(uint *)(rctx + 0x14) = uVar10 << 8;
      bVar3 = *(byte *)((int)&local_34->sn + 3);
      in_a2 = (ASN1_OBJECT *)(uint)bVar3;
      uVar4 = CONCAT11(bVar1,bVar3);
      uVar10 = (uint)uVar4;
      pAVar25 = (ASN1_OBJECT *)&local_34->ln;
      if (uVar9 != 2) {
        *(uint *)(rctx + 0x14) = uVar10 << 8;
        path = (char *)(uint)*(byte *)&local_34->ln;
        uVar5 = CONCAT21(uVar4,*(byte *)&local_34->ln);
        uVar10 = (uint)uVar5;
        pAVar25 = (ASN1_OBJECT *)((int)&local_34->ln + 1);
        if (uVar9 == 4) {
          path = (char *)((int)&local_34->ln + 2);
          *(uint *)(rctx + 0x14) = uVar10 << 8;
          uVar10 = CONCAT31(uVar5,*(undefined *)((int)&local_34->ln + 1));
          pAVar25 = (ASN1_OBJECT *)path;
        }
        local_34 = pAVar25;
        *(uint *)(rctx + 0x14) = uVar10;
        pAVar25 = local_34;
        pAVar22 = local_34;
        if (local_4c <= uVar10) goto LAB_005acbf8;
      }
    }
    local_34 = pAVar25;
    *(undefined4 *)rctx = 4;
    *(uint *)(rctx + 0x14) = uVar9 + 2 + uVar10;
  }
  else {
    *(undefined4 *)rctx = 4;
    *(uint *)(rctx + 0x14) = bVar1 + 2;
    local_34 = pAVar22;
  }
LAB_005ac9c0:
  pcVar27 = *(code **)(local_58 + -0x7fc8);
LAB_005ac9c4:
  path = (char *)0x3;
  iVar13 = (*pcVar27)(*(undefined4 *)(rctx + 0x10),3,0,pAStack_d4);
  in_a2 = *(ASN1_OBJECT **)(rctx + 0x14);
  pAVar22 = local_34;
  if (iVar13 < (int)in_a2) goto LAB_005ac9e8;
  path = (char *)pAStack_d4;
  pOVar11 = d2i_OCSP_RESPONSE((OCSP_RESPONSE **)0x0,(uchar **)pAStack_d4,(long)in_a2);
  *presp = pOVar11;
  pAVar22 = local_34;
  if (pOVar11 != (OCSP_RESPONSE *)0x0) {
    pAVar25 = (ASN1_OBJECT *)0x1;
    *(undefined4 *)rctx = 0x1008;
    goto LAB_005ac8a0;
  }
LAB_005acbf8:
  local_34 = pAVar22;
  pAVar25 = (ASN1_OBJECT *)0x0;
  *(undefined4 *)rctx = 0x1000;
LAB_005ac8a0:
  if (local_2c == *(BIO **)puStack_7c) {
    return (int)pAVar25;
  }
  pcStack_74 = OCSP_sendreq_bio;
  pBStack_c4 = local_2c;
  (**(code **)(local_58 + -0x5330))();
  puStack_c0 = PTR___stack_chk_guard_006a9ae8;
  pcVar24 = (char *)0xffffffff;
  puStack_a0 = &_gp;
  uStack_84 = 4;
  pOStack_98 = (OCSP_SIGNATURE *)0x0;
  iStack_94 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_8c = pAStack_d4;
  pAStack_88 = pAVar25;
  ppOStack_80 = ppOStack_c8;
  ppOStack_78 = presp;
  pAStack_d0 = (ASN1_OBJECT *)OCSP_sendreq_new(pBStack_c4,path,(OCSP_REQUEST *)in_a2,-1);
  if (pAStack_d0 == (ASN1_OBJECT *)0x0) {
LAB_005ad030:
    pOVar12 = (OCSP_SIGNATURE *)0x0;
    pAStack_d0 = pAVar25;
  }
  else {
    ppOStack_c8 = &pOStack_98;
    uStack_cc = 0xffffffff;
    do {
      path = (char *)pAStack_d0;
      pAStack_d4 = (ASN1_OBJECT *)
                   OCSP_sendreq_nbio((OCSP_RESPONSE **)ppOStack_c8,(OCSP_REQ_CTX *)pAStack_d0);
      if (pAStack_d4 != (ASN1_OBJECT *)0xffffffff) break;
      path = &DAT_00000008;
      iVar13 = (**(code **)(puStack_a0 + -0x7578))(pBStack_c4);
    } while (iVar13 != 0);
    if (pAStack_d0->data != (uchar *)0x0) {
      (**(code **)(puStack_a0 + -0x7f70))();
    }
    if ((ASN1_TYPE *)pAStack_d0->ln != (ASN1_TYPE *)0x0) {
      (**(code **)(puStack_a0 + -0x7f58))();
    }
    (**(code **)(puStack_a0 + -0x7f58))(pAStack_d0);
    pOVar12 = pOStack_98;
    pAVar25 = pAStack_d0;
    if (pAStack_d4 == (ASN1_OBJECT *)0x0) goto LAB_005ad030;
  }
  if (iStack_94 == *(int *)puStack_c0) {
    return (int)pOVar12;
  }
  uStack_b4 = 0x5ad044;
  iStack_160 = iStack_94;
  (**(code **)(puStack_a0 + -0x5330))();
  puStack_15c = PTR___stack_chk_guard_006a9ae8;
  puStack_128 = &_gp;
  iStack_dc = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAVar25 = (ASN1_OBJECT *)path;
  pAVar22 = in_a2;
  pAStack_bc = unaff_s6;
  pAStack_b8 = unaff_s7;
  if (iStack_160 == 0) {
    iStack_160 = (*(code *)PTR_EVP_sha1_006a75d0)();
  }
  if ((ASN1_OBJECT *)path == (ASN1_OBJECT *)0x0) {
    iStack_150 = 0;
    uStack_154 = (**(code **)(puStack_128 + -0x7ee0))(in_a2);
  }
  else {
    uStack_154 = (**(code **)(puStack_128 + -0x76fc))(path);
    iStack_150 = (**(code **)(puStack_128 + -0x7e44))(path);
  }
  ppAStack_14c = (ASN1_OBJECT **)(**(code **)(puStack_128 + -0x6fb8))(in_a2);
  pOStack_164 = OCSP_CERTID_new();
  if (pOStack_164 == (OCSP_CERTID *)0x0) {
LAB_005ad160:
    auStack_120._0_4_ = pAVar22;
    pOVar14 = (OCSP_CERTID *)0x0;
  }
  else {
    in_a2 = (ASN1_OBJECT *)pOStack_164->hashAlgorithm;
    if ((ASN1_OBJECT *)in_a2->sn != (ASN1_OBJECT *)0x0) {
      (**(code **)(puStack_128 + -0x7ddc))();
    }
    iVar13 = (**(code **)(puStack_128 + -0x7a14))(iStack_160);
    if (iVar13 == 0) {
      pcVar27 = *(code **)(puStack_128 + -0x6eac);
      pAVar22 = (ASN1_OBJECT *)&DAT_00000078;
      iStack_130 = 0x75;
LAB_005ad13c:
      pcVar24 = "ocsp_lib.c";
      pAVar25 = (ASN1_OBJECT *)&DAT_00000065;
      (*pcVar27)(0x27);
LAB_005ad150:
      OCSP_CERTID_free(pOStack_164);
      goto LAB_005ad160;
    }
    pAVar21 = (ASN1_OBJECT *)(**(code **)(puStack_128 + -0x7ca0))(iVar13);
    in_a2->sn = (char *)pAVar21;
    if (pAVar21 == (ASN1_OBJECT *)0x0) goto LAB_005ad150;
    pAVar18 = (ASN1_TYPE *)(**(code **)(puStack_128 + -0x6f14))();
    in_a2->ln = (char **)pAVar18;
    if (pAVar18 == (ASN1_TYPE *)0x0) goto LAB_005ad150;
    pcVar27 = *(code **)(puStack_128 + -0x5b74);
    unaff_s7 = (ASN1_OBJECT *)auStack_120;
    in_a2 = (ASN1_OBJECT *)(auStack_120 + 4);
    pAVar18->type = 5;
    pcVar24 = (char *)unaff_s7;
    iVar13 = (*pcVar27)(uStack_154,iStack_160,in_a2);
    if (iVar13 == 0) {
      pcVar27 = *(code **)(puStack_128 + -0x6eac);
      pAVar22 = (ASN1_OBJECT *)0x66;
      iStack_130 = 0x91;
      goto LAB_005ad13c;
    }
    pAVar25 = in_a2;
    pAVar22 = auStack_120._0_4_;
    iVar13 = (**(code **)(puStack_128 + -0x6774))(pOStack_164->issuerNameHash);
    if (iVar13 == 0) goto LAB_005ad150;
    pAVar25 = *ppAStack_14c;
    uStack_12c = 0;
    pAVar22 = in_a2;
    pcVar24 = (char *)unaff_s7;
    iStack_130 = iStack_160;
    iVar13 = (**(code **)(puStack_128 + -0x73cc))(ppAStack_14c[2]);
    if ((iVar13 == 0) ||
       (pAVar25 = in_a2, iVar13 = (**(code **)(puStack_128 + -0x6774))(pOStack_164->issuerKeyHash),
       pAVar22 = auStack_120._0_4_, iVar13 == 0)) goto LAB_005ad150;
    pOVar14 = pOStack_164;
    if (iStack_150 != 0) {
      (**(code **)(puStack_128 + -0x7f4c))(pOStack_164->serialNumber);
      pAVar19 = (ASN1_INTEGER *)(**(code **)(puStack_128 + -0x5b70))(iStack_150);
      pOStack_164->serialNumber = pAVar19;
      pAVar22 = auStack_120._0_4_;
      if (pAVar19 == (ASN1_INTEGER *)0x0) goto LAB_005ad150;
    }
  }
  if (iStack_dc == *(int *)puStack_15c) {
    return (int)pOVar14;
  }
  pcStack_144 = OCSP_cert_id_new;
  iVar13 = iStack_dc;
  (**(code **)(puStack_128 + -0x5330))();
  puVar8 = PTR___stack_chk_guard_006a9ae8;
  puStack_16c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  pAVar22 = pAVar25;
  pAStack_158 = in_a2;
  pAStack_148 = unaff_s7;
  pOVar14 = OCSP_CERTID_new();
  if (pOVar14 != (OCSP_CERTID *)0x0) {
    pXVar26 = pOVar14->hashAlgorithm;
    if (pXVar26->algorithm != (ASN1_OBJECT *)0x0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a7004)();
    }
    iVar15 = (*(code *)PTR_EVP_MD_type_006a73cc)(iVar13);
    if (iVar15 == 0) {
      uVar23 = 0x78;
      uVar16 = 0x75;
LAB_005ad390:
      pAVar21 = (ASN1_OBJECT *)&DAT_00000065;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x65,uVar23,"ocsp_lib.c",uVar16);
    }
    else {
      pAVar17 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar15);
      pXVar26->algorithm = pAVar17;
      pAVar21 = pAVar22;
      if (pAVar17 != (ASN1_OBJECT *)0x0) {
        pAVar18 = (ASN1_TYPE *)(*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
        pXVar26->parameter = pAVar18;
        puVar7 = PTR_X509_NAME_digest_006a926c;
        pAVar21 = pAVar22;
        if (pAVar18 != (ASN1_TYPE *)0x0) {
          pAVar22 = aAStack_1ac;
          pAVar18->type = 5;
          iVar15 = (*(code *)puVar7)(pAVar25,iVar13,pAVar22,&uStack_1b0);
          if (iVar15 == 0) {
            uVar23 = 0x66;
            uVar16 = 0x91;
            goto LAB_005ad390;
          }
          pAVar21 = pAVar22;
          iVar15 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)
                             (pOVar14->issuerNameHash,pAVar22,uStack_1b0);
          if (iVar15 != 0) {
            pAVar21 = (ASN1_OBJECT *)(auStack_120._0_4_)->sn;
            iVar13 = (*(code *)PTR_EVP_Digest_006a7a14)
                               ((auStack_120._0_4_)->nid,pAVar21,pAVar22,&uStack_1b0,iVar13,0);
            if ((iVar13 != 0) &&
               (iVar13 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)
                                   (pOVar14->issuerKeyHash,pAVar22,uStack_1b0), pAVar21 = pAVar22,
               iVar13 != 0)) {
              if ((ASN1_OBJECT *)pcVar24 == (ASN1_OBJECT *)0x0) goto LAB_005ad3b8;
              (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(pOVar14->serialNumber);
              pAVar19 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_INTEGER_dup_006a9270)(pcVar24);
              pOVar14->serialNumber = pAVar19;
              pAVar21 = pAVar22;
              if (pAVar19 != (ASN1_INTEGER *)0x0) goto LAB_005ad3b8;
            }
          }
        }
      }
    }
    OCSP_CERTID_free(pOVar14);
    pAVar22 = pAVar21;
  }
  pOVar14 = (OCSP_CERTID *)0x0;
LAB_005ad3b8:
  if (puStack_16c == *(undefined4 **)puVar8) {
    return (int)pOVar14;
  }
  puVar20 = puStack_16c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar13 = (*(code *)PTR_OBJ_cmp_006a8cc4)(*(undefined4 *)*puVar20,((ASN1_OBJECT *)pAVar22->sn)->sn)
  ;
  if ((iVar13 == 0) &&
     (iVar13 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)(puVar20[1],(ASN1_TYPE *)pAVar22->ln),
     iVar13 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x005ad590. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar13 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)(puVar20[2],pAVar22->nid);
    return iVar13;
  }
  return iVar13;
}

