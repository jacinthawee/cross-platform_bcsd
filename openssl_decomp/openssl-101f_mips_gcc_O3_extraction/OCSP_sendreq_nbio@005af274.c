
int OCSP_sendreq_nbio(OCSP_RESPONSE **presp,OCSP_REQ_CTX *rctx)

{
  byte bVar1;
  ushort uVar2;
  uint3 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  OCSP_RESPONSE *pOVar8;
  int iVar9;
  ASN1_OBJECT *pAVar10;
  OCSP_CERTID *pOVar11;
  int iVar12;
  undefined4 uVar13;
  ASN1_OBJECT *pAVar14;
  ASN1_TYPE *pAVar15;
  ASN1_INTEGER *pAVar16;
  uchar *****pppppuVar17;
  undefined4 *puVar18;
  char *path;
  uchar ******ppppppuVar19;
  ASN1_OBJECT *pAVar20;
  ASN1_OBJECT *in_a2;
  ASN1_OBJECT *pAVar21;
  undefined4 uVar22;
  char *pcVar23;
  X509_ALGOR *pXVar24;
  ASN1_OBJECT *unaff_s6;
  ASN1_OBJECT *unaff_s7;
  code *pcVar25;
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
  int iStack_d4;
  ASN1_OBJECT *pAStack_d0;
  undefined4 uStack_cc;
  OCSP_RESPONSE **ppOStack_c8;
  BIO *pBStack_c4;
  undefined *puStack_c0;
  ASN1_OBJECT *pAStack_bc;
  ASN1_OBJECT *pAStack_b8;
  undefined4 uStack_b4;
  undefined *puStack_a0;
  OCSP_RESPONSE *pOStack_98;
  int iStack_94;
  uchar ******ppppppuStack_8c;
  uint uStack_88;
  undefined4 uStack_84;
  byte **ppbStack_80;
  undefined *puStack_7c;
  OCSP_RESPONSE **ppOStack_78;
  code *pcStack_74;
  ASN1_OBJECT *local_60;
  undefined *local_58;
  uint local_4c;
  ASN1_OBJECT *local_48;
  uchar ******local_44;
  uchar ******local_40;
  uchar *****local_3c;
  uchar ******local_34;
  byte *local_30;
  BIO *local_2c;
  
  puStack_7c = PTR___stack_chk_guard_006aabf0;
  uVar6 = *(uint *)rctx;
  ppppppuStack_8c = (uchar ******)&local_34;
  ppbStack_80 = &local_30;
  local_58 = &_gp;
  local_4c = 0x19001;
  local_2c = *(BIO **)PTR___stack_chk_guard_006aabf0;
  path = (char *)rctx;
LAB_005af2dc:
  uStack_88 = uVar6 & 0x1000;
  pcVar25 = *(code **)(local_58 + -0x7924);
  if (uStack_88 == 0) goto LAB_005af3f4;
  pcVar25 = *(code **)(local_58 + -0x7fc8);
  if (uVar6 != 4) {
    do {
      if ((int)uVar6 < 5) {
        if ((int)uVar6 < 1) {
LAB_005af314:
          uStack_88 = 0;
          goto LAB_005af318;
        }
        if (2 < (int)uVar6) goto LAB_005af478;
        unaff_s6 = (ASN1_OBJECT *)&DAT_0000000d;
        goto LAB_005af688;
      }
      if (uVar6 != 0x1007) {
        if (uVar6 == 0x1008) {
          uStack_88 = 1;
        }
        else {
          if (uVar6 != 0x1006) goto LAB_005af314;
          iVar9 = (**(code **)(local_58 + -0x7fc8))
                            (*(undefined4 *)(rctx + 0x10),3,0,ppppppuStack_8c);
          in_a2 = *(ASN1_OBJECT **)(rctx + 0x14);
          path = (char *)((int)local_34 + (iVar9 - (int)in_a2));
          iVar9 = (**(code **)(local_58 + -0x7fcc))(*(undefined4 *)(rctx + 0xc));
          if (0 < iVar9) {
            iVar12 = *(int *)(rctx + 0x14);
            *(int *)(rctx + 0x14) = iVar12 - iVar9;
            ppppppuVar19 = local_34;
            if (iVar12 - iVar9 == 0) {
              pcVar25 = *(code **)(local_58 + -0x7fc8);
              *(undefined4 *)rctx = 0x1007;
              (*pcVar25)(*(undefined4 *)(rctx + 0x10),1,0,0);
              goto LAB_005af3c4;
            }
            goto LAB_005af460;
          }
LAB_005af94c:
          path = &DAT_00000008;
          uStack_88 = 0xffffffff;
          iVar9 = (**(code **)(local_58 + -0x758c))(*(undefined4 *)(rctx + 0xc));
          ppppppuVar19 = local_34;
          if (iVar9 == 0) goto LAB_005af670;
        }
        goto LAB_005af318;
      }
LAB_005af3c4:
      in_a2 = (ASN1_OBJECT *)0x0;
      iVar9 = (**(code **)(local_58 + -0x7fc8))(*(undefined4 *)(rctx + 0xc),0xb,0,0);
      if (iVar9 < 1) goto LAB_005af94c;
      uStack_88 = 0;
      *(undefined4 *)rctx = 1;
      pcVar25 = *(code **)(local_58 + -0x7924);
LAB_005af3f4:
      in_a2 = *(ASN1_OBJECT **)(rctx + 8);
      unaff_s6 = (ASN1_OBJECT *)(*pcVar25)(*(undefined4 *)(rctx + 0xc),*(undefined4 *)(rctx + 4));
      if ((int)unaff_s6 < 1) {
        path = &DAT_00000008;
        iVar9 = (**(code **)(local_58 + -0x758c))(*(undefined4 *)(rctx + 0xc));
        uStack_88 = -(uint)(iVar9 != 0);
        goto LAB_005af318;
      }
      path = *(char **)(rctx + 4);
      in_a2 = unaff_s6;
      pAVar10 = (ASN1_OBJECT *)(**(code **)(local_58 + -0x7fcc))(*(undefined4 *)(rctx + 0x10));
      if (unaff_s6 != pAVar10) goto LAB_005af318;
      uVar6 = *(uint *)rctx;
    } while (uVar6 != 4);
    goto LAB_005af438;
  }
  goto LAB_005af43c;
LAB_005af688:
  pcVar25 = *(code **)(local_58 + -0x7fc8);
  do {
    in_a2 = (ASN1_OBJECT *)0x0;
    path = (char *)0x3;
    unaff_s7 = (ASN1_OBJECT *)(*pcVar25)(*(undefined4 *)(rctx + 0x10),3,0,ppppppuStack_8c);
    if ((int)unaff_s7 < 1) {
LAB_005af810:
      ppppppuVar19 = local_34;
      if (*(int *)(rctx + 8) <= (int)unaff_s7) goto LAB_005af670;
      uVar6 = *(uint *)rctx;
      goto LAB_005af2dc;
    }
    path = &DAT_0000000a;
    in_a2 = unaff_s7;
    iVar9 = (**(code **)(local_58 + -0x53f0))(local_34);
    if (iVar9 == 0) goto LAB_005af810;
    in_a2 = *(ASN1_OBJECT **)(rctx + 8);
    path = *(char **)(rctx + 4);
    iVar9 = (**(code **)(local_58 + -0x7910))(*(undefined4 *)(rctx + 0x10));
    if (iVar9 < 1) {
      path = &DAT_00000008;
      iVar9 = (**(code **)(local_58 + -0x758c))(*(undefined4 *)(rctx + 0x10));
      ppppppuVar19 = local_34;
      if (iVar9 == 0) goto LAB_005af670;
      uVar6 = *(uint *)rctx;
      goto LAB_005af2dc;
    }
    ppppppuVar19 = local_34;
    if (iVar9 == *(int *)(rctx + 8)) goto LAB_005af670;
    if (*(int *)rctx == 1) break;
    bVar1 = *(byte *)*(uchar *******)(rctx + 4);
    local_34 = *(uchar *******)(rctx + 4);
    while( true ) {
      if (bVar1 == 0) {
        *(undefined4 *)rctx = 3;
        goto LAB_005af478;
      }
      if ((bVar1 != 0xd) && (pcVar25 = *(code **)(local_58 + -0x7fc8), bVar1 != 10)) break;
      bVar1 = *(byte *)(uchar ******)((int)local_34 + 1);
      local_34 = (uchar ******)((int)local_34 + 1);
    }
  } while( true );
  pAVar10 = *(ASN1_OBJECT **)(rctx + 4);
  local_48 = (ASN1_OBJECT *)(int)*(char *)&pAVar10->sn;
  if (local_48 == (ASN1_OBJECT *)0x0) {
LAB_005af79c:
    pcVar25 = *(code **)(local_58 + -0x6eb0);
    local_60 = (ASN1_OBJECT *)&DAT_000000c8;
    unaff_s7 = pAVar10;
LAB_005af7e0:
    in_a2 = (ASN1_OBJECT *)&DAT_00000073;
    path = &DAT_00000076;
    uStack_88 = 0;
    (*pcVar25)(0x27,0x76,0x73,"ocsp_ht.c");
    *(undefined4 *)rctx = 0x1000;
    goto LAB_005af318;
  }
  ppppppuVar19 = (uchar ******)(**(code **)(local_58 + -0x5498))();
  pppppuVar17 = *ppppppuVar19;
  pAVar20 = local_48;
  while (uVar6 = (uint)pAVar20 & 0xff, (*(ushort *)((int)pppppuVar17 + uVar6 * 2) & 0x20) == 0) {
    pAVar10 = (ASN1_OBJECT *)((int)&pAVar10->sn + 1);
    pAVar20 = (ASN1_OBJECT *)(int)*(char *)&pAVar10->sn;
    if (pAVar20 == (ASN1_OBJECT *)0x0) goto LAB_005af79c;
  }
  while (unaff_s7 = (ASN1_OBJECT *)((int)&pAVar10->sn + 1), pAVar20 = pAVar10,
        (*(ushort *)((int)pppppuVar17 + uVar6 * 2) & 0x20) != 0) {
    uVar6 = (int)*(char *)&unaff_s7->sn & 0xff;
    pAVar10 = unaff_s7;
    if ((int)*(char *)&unaff_s7->sn == 0) {
      pcVar25 = *(code **)(local_58 + -0x6eb0);
      local_60 = (ASN1_OBJECT *)0xd3;
      goto LAB_005af7e0;
    }
  }
  while (pcVar25 = *(code **)(local_58 + -0x53a8), unaff_s7 = pAVar10,
        (*(ushort *)((int)pppppuVar17 + uVar6 * 2) & 0x20) == 0) {
    pAVar20 = (ASN1_OBJECT *)((int)&pAVar20->sn + 1);
    uVar6 = (int)*(char *)&pAVar20->sn & 0xff;
    if ((int)*(char *)&pAVar20->sn == 0) {
      pcVar25 = *(code **)(local_58 + -0x6eb0);
      local_60 = (ASN1_OBJECT *)0xde;
      goto LAB_005af7e0;
    }
  }
  in_a2 = (ASN1_OBJECT *)&DAT_0000000a;
  *(undefined *)&pAVar20->sn = 0;
  local_48 = pAVar20;
  local_44 = ppppppuVar19;
  path = (char *)(*pcVar25)(pAVar10,ppbStack_80);
  ppppppuVar19 = local_34;
  if (*local_30 != 0) goto LAB_005af670;
  uVar6 = (uint)*(char *)((int)&local_48->sn + 1);
  local_48 = (ASN1_OBJECT *)((int)&local_48->sn + 1);
  if (uVar6 != 0) {
    pppppuVar17 = *local_44;
    pAVar20 = local_48;
LAB_005af574:
    local_48 = (ASN1_OBJECT *)((int)&pAVar20->sn + 1);
    if ((*(ushort *)((int)pppppuVar17 + (uVar6 & 0xff) * 2) & 0x20) != 0) goto LAB_005af568;
    local_40 = local_44;
    local_48 = pAVar20;
    local_44 = (uchar ******)path;
    local_3c = pppppuVar17;
    iVar9 = (**(code **)(local_58 + -0x53b0))(pAVar20);
    local_30 = (byte *)((int)local_48 + iVar9 + -1);
    pppppuVar17 = local_3c;
    while (path = (char *)local_44,
          (*(ushort *)((int)pppppuVar17 + (uint)*local_30 * 2) & 0x20) != 0) {
      *local_30 = 0;
      local_30 = local_30 + -1;
      pppppuVar17 = *local_40;
    }
  }
LAB_005af604:
  if (path != &DAT_000000c8) {
    local_60 = (ASN1_OBJECT *)0xfa;
    (**(code **)(local_58 + -0x6eb0))(0x27,0x76,0x72,"ocsp_ht.c");
    in_a2 = pAVar10;
    if (*(char *)&local_48->sn == '\0') {
      path = "Code=";
      (**(code **)(local_58 + -0x6c7c))(2);
      ppppppuVar19 = local_34;
    }
    else {
      local_60 = local_48;
      path = "Code=";
      (**(code **)(local_58 + -0x6c7c))(4,"Code=",pAVar10,",Reason=");
      ppppppuVar19 = local_34;
    }
    goto LAB_005af670;
  }
  *(undefined4 *)rctx = 2;
  goto LAB_005af688;
LAB_005af568:
  uVar6 = (uint)*(char *)&local_48->sn;
  pAVar20 = local_48;
  if (uVar6 == 0) goto LAB_005af604;
  goto LAB_005af574;
LAB_005af478:
  in_a2 = (ASN1_OBJECT *)0x0;
  path = (char *)0x3;
  iVar9 = (**(code **)(local_58 + -0x7fc8))(*(undefined4 *)(rctx + 0x10),3,0,ppppppuStack_8c);
  ppppppuVar19 = local_34;
  if (iVar9 < 2) {
LAB_005af460:
    local_34 = ppppppuVar19;
    uVar6 = *(uint *)rctx;
    goto LAB_005af2dc;
  }
  ppppppuVar19 = (uchar ******)((int)local_34 + 1);
  path = (char *)(uint)*(byte *)local_34;
  if (path != &DAT_00000030) goto LAB_005af670;
  bVar1 = *(byte *)((int)local_34 + 1);
  path = (char *)(int)(char)bVar1;
  if ((int)path < 0) {
    uVar6 = bVar1 & 0x7f;
    if (iVar9 < 6) goto LAB_005af460;
    if (3 < uVar6 - 1) goto LAB_005af670;
    *(undefined4 *)(rctx + 0x14) = 0;
    bVar1 = *(byte *)((int)local_34 + 2);
    uVar7 = (uint)bVar1;
    ppppppuVar19 = (uchar ******)((int)local_34 + 3);
    if (uVar6 != 1) {
      *(uint *)(rctx + 0x14) = uVar7 << 8;
      in_a2 = (ASN1_OBJECT *)(uint)*(byte *)((int)local_34 + 3);
      uVar2 = CONCAT11(bVar1,*(byte *)((int)local_34 + 3));
      uVar7 = (uint)uVar2;
      ppppppuVar19 = local_34 + 1;
      if (uVar6 != 2) {
        *(uint *)(rctx + 0x14) = uVar7 << 8;
        path = (char *)(uint)*(byte *)(local_34 + 1);
        uVar3 = CONCAT21(uVar2,*(byte *)(local_34 + 1));
        uVar7 = (uint)uVar3;
        ppppppuVar19 = (uchar ******)((int)local_34 + 5);
        if (uVar6 == 4) {
          path = (char *)((int)local_34 + 6);
          *(uint *)(rctx + 0x14) = uVar7 << 8;
          uVar7 = CONCAT31(uVar3,*(byte *)((int)local_34 + 5));
          ppppppuVar19 = (uchar ******)path;
        }
        local_34 = ppppppuVar19;
        *(uint *)(rctx + 0x14) = uVar7;
        ppppppuVar19 = local_34;
        if (local_4c <= uVar7) goto LAB_005af670;
      }
    }
    local_34 = ppppppuVar19;
    *(undefined4 *)rctx = 4;
    *(uint *)(rctx + 0x14) = uVar6 + 2 + uVar7;
  }
  else {
    *(undefined4 *)rctx = 4;
    *(uint *)(rctx + 0x14) = bVar1 + 2;
    local_34 = ppppppuVar19;
  }
LAB_005af438:
  pcVar25 = *(code **)(local_58 + -0x7fc8);
LAB_005af43c:
  path = (char *)0x3;
  iVar9 = (*pcVar25)(*(undefined4 *)(rctx + 0x10),3,0,ppppppuStack_8c);
  in_a2 = *(ASN1_OBJECT **)(rctx + 0x14);
  ppppppuVar19 = local_34;
  if (iVar9 < (int)in_a2) goto LAB_005af460;
  path = (char *)ppppppuStack_8c;
  pOVar8 = d2i_OCSP_RESPONSE((OCSP_RESPONSE **)0x0,(uchar **)ppppppuStack_8c,(long)in_a2);
  *presp = pOVar8;
  ppppppuVar19 = local_34;
  if (pOVar8 != (OCSP_RESPONSE *)0x0) {
    uStack_88 = 1;
    *(undefined4 *)rctx = 0x1008;
    goto LAB_005af318;
  }
LAB_005af670:
  local_34 = ppppppuVar19;
  uStack_88 = 0;
  *(undefined4 *)rctx = 0x1000;
LAB_005af318:
  if (local_2c == *(BIO **)puStack_7c) {
    return uStack_88;
  }
  pcStack_74 = OCSP_sendreq_bio;
  pBStack_c4 = local_2c;
  (**(code **)(local_58 + -0x5328))();
  puStack_c0 = PTR___stack_chk_guard_006aabf0;
  pcVar23 = (char *)0xffffffff;
  ppOStack_c8 = &pOStack_98;
  uStack_84 = 4;
  puStack_a0 = &_gp;
  pOStack_98 = (OCSP_RESPONSE *)0x0;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppOStack_78 = presp;
  pAStack_d0 = (ASN1_OBJECT *)OCSP_sendreq_new(pBStack_c4,path,(OCSP_REQUEST *)in_a2,-1);
  do {
    pAVar10 = pAStack_d0;
    iStack_d4 = OCSP_sendreq_nbio(ppOStack_c8,(OCSP_REQ_CTX *)pAStack_d0);
    if (iStack_d4 != -1) break;
    pAVar10 = (ASN1_OBJECT *)&DAT_00000008;
    iVar9 = (**(code **)(puStack_a0 + -0x758c))(pBStack_c4);
  } while (iVar9 != 0);
  if (pAStack_d0->data != (uchar *)0x0) {
    (**(code **)(puStack_a0 + -0x7f70))();
  }
  if ((ASN1_TYPE *)pAStack_d0->ln != (ASN1_TYPE *)0x0) {
    (**(code **)(puStack_a0 + -0x7f58))();
  }
  (**(code **)(puStack_a0 + -0x7f58))(pAStack_d0);
  pOVar8 = pOStack_98;
  if (iStack_d4 == 0) {
    pOVar8 = (OCSP_RESPONSE *)0x0;
  }
  if (iStack_94 == *(int *)puStack_c0) {
    return (int)pOVar8;
  }
  uStack_b4 = 0x5afab4;
  iStack_160 = iStack_94;
  (**(code **)(puStack_a0 + -0x5328))();
  puStack_15c = PTR___stack_chk_guard_006aabf0;
  uStack_cc = 0xffffffff;
  puStack_128 = &_gp;
  iStack_dc = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar20 = pAVar10;
  pAVar21 = in_a2;
  pAStack_bc = unaff_s6;
  pAStack_b8 = unaff_s7;
  if (iStack_160 == 0) {
    iStack_160 = (*(code *)PTR_EVP_sha1_006a86c4)();
  }
  if (pAVar10 == (ASN1_OBJECT *)0x0) {
    iStack_150 = 0;
    uStack_154 = (**(code **)(puStack_128 + -0x7ee0))(in_a2);
  }
  else {
    uStack_154 = (**(code **)(puStack_128 + -0x7710))(pAVar10);
    iStack_150 = (**(code **)(puStack_128 + -0x7e44))(pAVar10);
  }
  ppAStack_14c = (ASN1_OBJECT **)(**(code **)(puStack_128 + -0x6fc8))(in_a2);
  pOStack_164 = OCSP_CERTID_new();
  if (pOStack_164 == (OCSP_CERTID *)0x0) {
LAB_005afbd0:
    auStack_120._0_4_ = pAVar21;
    pOVar11 = (OCSP_CERTID *)0x0;
  }
  else {
    in_a2 = (ASN1_OBJECT *)pOStack_164->hashAlgorithm;
    if ((ASN1_OBJECT *)in_a2->sn != (ASN1_OBJECT *)0x0) {
      (**(code **)(puStack_128 + -0x7ddc))();
    }
    iVar9 = (**(code **)(puStack_128 + -0x7a14))(iStack_160);
    if (iVar9 == 0) {
      pcVar25 = *(code **)(puStack_128 + -0x6eb0);
      pAVar21 = (ASN1_OBJECT *)&DAT_00000078;
      iStack_130 = 0x74;
LAB_005afbac:
      pcVar23 = "ocsp_lib.c";
      pAVar20 = (ASN1_OBJECT *)&DAT_00000065;
      (*pcVar25)(0x27);
LAB_005afbc0:
      OCSP_CERTID_free(pOStack_164);
      goto LAB_005afbd0;
    }
    pAVar10 = (ASN1_OBJECT *)(**(code **)(puStack_128 + -0x7ca0))(iVar9);
    in_a2->sn = (char *)pAVar10;
    if (pAVar10 == (ASN1_OBJECT *)0x0) goto LAB_005afbc0;
    pAVar15 = (ASN1_TYPE *)(**(code **)(puStack_128 + -0x6f24))();
    in_a2->ln = (char **)pAVar15;
    if (pAVar15 == (ASN1_TYPE *)0x0) goto LAB_005afbc0;
    pcVar25 = *(code **)(puStack_128 + -0x5b68);
    unaff_s7 = (ASN1_OBJECT *)auStack_120;
    in_a2 = (ASN1_OBJECT *)(auStack_120 + 4);
    pAVar15->type = 5;
    pcVar23 = (char *)unaff_s7;
    iVar9 = (*pcVar25)(uStack_154,iStack_160,in_a2);
    if (iVar9 == 0) {
      pcVar25 = *(code **)(puStack_128 + -0x6eb0);
      pAVar21 = (ASN1_OBJECT *)0x66;
      iStack_130 = 0x8b;
      goto LAB_005afbac;
    }
    pAVar20 = in_a2;
    pAVar21 = auStack_120._0_4_;
    iVar9 = (**(code **)(puStack_128 + -0x6750))(pOStack_164->issuerNameHash);
    if (iVar9 == 0) goto LAB_005afbc0;
    pAVar20 = *ppAStack_14c;
    uStack_12c = 0;
    pAVar21 = in_a2;
    pcVar23 = (char *)unaff_s7;
    iStack_130 = iStack_160;
    iVar9 = (**(code **)(puStack_128 + -0x73dc))(ppAStack_14c[2]);
    if ((iVar9 == 0) ||
       (pAVar20 = in_a2, iVar9 = (**(code **)(puStack_128 + -0x6750))(pOStack_164->issuerKeyHash),
       pAVar21 = auStack_120._0_4_, iVar9 == 0)) goto LAB_005afbc0;
    pOVar11 = pOStack_164;
    if (iStack_150 != 0) {
      (**(code **)(puStack_128 + -0x7f4c))(pOStack_164->serialNumber);
      pAVar16 = (ASN1_INTEGER *)(**(code **)(puStack_128 + -0x5b64))(iStack_150);
      pOStack_164->serialNumber = pAVar16;
      pAVar21 = auStack_120._0_4_;
      if (pAVar16 == (ASN1_INTEGER *)0x0) goto LAB_005afbc0;
    }
  }
  if (iStack_dc == *(int *)puStack_15c) {
    return (int)pOVar11;
  }
  pcStack_144 = OCSP_cert_id_new;
  iVar9 = iStack_dc;
  (**(code **)(puStack_128 + -0x5328))();
  puVar5 = PTR___stack_chk_guard_006aabf0;
  puStack_16c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pAVar10 = pAVar20;
  pAStack_158 = in_a2;
  pAStack_148 = unaff_s7;
  pOVar11 = OCSP_CERTID_new();
  if (pOVar11 != (OCSP_CERTID *)0x0) {
    pXVar24 = pOVar11->hashAlgorithm;
    if (pXVar24->algorithm != (ASN1_OBJECT *)0x0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a8104)();
    }
    iVar12 = (*(code *)PTR_EVP_MD_type_006a84cc)(iVar9);
    if (iVar12 == 0) {
      uVar22 = 0x78;
      uVar13 = 0x74;
LAB_005afe00:
      pAVar21 = (ASN1_OBJECT *)&DAT_00000065;
      (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x65,uVar22,"ocsp_lib.c",uVar13);
    }
    else {
      pAVar14 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar12);
      pXVar24->algorithm = pAVar14;
      pAVar21 = pAVar10;
      if (pAVar14 != (ASN1_OBJECT *)0x0) {
        pAVar15 = (ASN1_TYPE *)(*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
        pXVar24->parameter = pAVar15;
        puVar4 = PTR_X509_NAME_digest_006aa378;
        pAVar21 = pAVar10;
        if (pAVar15 != (ASN1_TYPE *)0x0) {
          pAVar10 = aAStack_1ac;
          pAVar15->type = 5;
          iVar12 = (*(code *)puVar4)(pAVar20,iVar9,pAVar10,&uStack_1b0);
          if (iVar12 == 0) {
            uVar22 = 0x66;
            uVar13 = 0x8b;
            goto LAB_005afe00;
          }
          pAVar21 = pAVar10;
          iVar12 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)
                             (pOVar11->issuerNameHash,pAVar10,uStack_1b0);
          if (iVar12 != 0) {
            pAVar21 = (ASN1_OBJECT *)(auStack_120._0_4_)->sn;
            iVar9 = (*(code *)PTR_EVP_Digest_006a8b04)
                              ((auStack_120._0_4_)->nid,pAVar21,pAVar10,&uStack_1b0,iVar9,0);
            if ((iVar9 != 0) &&
               (iVar9 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)
                                  (pOVar11->issuerKeyHash,pAVar10,uStack_1b0), pAVar21 = pAVar10,
               iVar9 != 0)) {
              if ((ASN1_OBJECT *)pcVar23 == (ASN1_OBJECT *)0x0) goto LAB_005afe28;
              (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(pOVar11->serialNumber);
              pAVar16 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_INTEGER_dup_006aa37c)(pcVar23);
              pOVar11->serialNumber = pAVar16;
              pAVar21 = pAVar10;
              if (pAVar16 != (ASN1_INTEGER *)0x0) goto LAB_005afe28;
            }
          }
        }
      }
    }
    OCSP_CERTID_free(pOVar11);
    pAVar10 = pAVar21;
  }
  pOVar11 = (OCSP_CERTID *)0x0;
LAB_005afe28:
  if (puStack_16c == *(undefined4 **)puVar5) {
    return (int)pOVar11;
  }
  puVar18 = puStack_16c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar9 = (*(code *)PTR_OBJ_cmp_006a9de4)(*(undefined4 *)*puVar18,((ASN1_OBJECT *)pAVar10->sn)->sn);
  if ((iVar9 == 0) &&
     (iVar9 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)(puVar18[1],(ASN1_TYPE *)pAVar10->ln),
     iVar9 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x005b0000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar9 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)(puVar18[2],pAVar10->nid);
    return iVar9;
  }
  return iVar9;
}

