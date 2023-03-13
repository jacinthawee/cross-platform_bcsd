
/* WARNING: Type propagation algorithm not settling */

int mime_parse_hdr(undefined4 param_1,char **param_2,char **param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  char **ppcVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  BIO *out;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  uint uVar12;
  char **ppcVar13;
  char **ppcVar14;
  char cVar15;
  code *pcVar16;
  ASN1_VALUE *val;
  BIO *pBVar17;
  BIO *pBVar18;
  char *pcVar19;
  char **unaff_s0;
  char **ppcVar20;
  undefined *unaff_s1;
  char *unaff_s2;
  undefined **unaff_s3;
  char **unaff_s4;
  char **unaff_s5;
  char **unaff_s6;
  char **unaff_s7;
  char **ppcVar21;
  code *pcVar22;
  undefined *puVar23;
  undefined4 unaff_s8;
  char acStack_8ee [1026];
  BIO *pBStack_4ec;
  int iStack_4e8;
  undefined *puStack_4e4;
  char **ppcStack_4e0;
  undefined **ppuStack_4dc;
  char **ppcStack_4d8;
  undefined *puStack_4d4;
  int iStack_4d0;
  char **ppcStack_4cc;
  char **ppcStack_4c8;
  code *pcStack_4c4;
  undefined4 uStack_4b0;
  undefined *puStack_4a8;
  undefined4 uStack_49c;
  char *apcStack_498 [3];
  int iStack_48c;
  char **ppcStack_488;
  undefined *puStack_484;
  char **ppcStack_480;
  undefined **ppuStack_47c;
  char **ppcStack_478;
  char **ppcStack_474;
  char **ppcStack_470;
  char **ppcStack_46c;
  undefined4 uStack_468;
  code *pcStack_464;
  undefined *local_450;
  undefined4 local_444;
  char **local_440;
  int local_43c;
  char **local_438;
  int *local_434;
  char local_42c;
  undefined local_42b [1023];
  int local_2c;
  
  local_450 = &_gp;
  local_434 = (int *)PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_444 = param_1;
  local_43c = (*(code *)PTR_sk_new_006a806c)(mime_hdr_cmp);
  puVar23 = local_450;
  if (local_43c == 0) {
    iVar5 = 0;
  }
  else {
    local_440 = (char **)0x0;
    unaff_s2 = (char *)0x0;
    unaff_s6 = (char **)&local_42c;
    unaff_s8 = 0x2401;
    unaff_s3 = &switchD_0060bbc8::switchdataD_00679dc0;
    unaff_s1 = (undefined *)0x3b;
    do {
      pcVar22 = *(code **)(puVar23 + -0x790c);
LAB_0060bb3c:
      param_3 = (char **)&DAT_00000400;
      param_2 = unaff_s6;
      iVar2 = (*pcVar22)(local_444);
      iVar5 = local_43c;
      puVar23 = local_450;
      if (iVar2 < 1) break;
      if ((char **)unaff_s2 == (char **)0x0) {
        uVar12 = (uint)local_42c;
        uVar9 = uVar12 & 0xff;
LAB_0060c15c:
        param_2 = (char **)0x1;
      }
      else {
        piVar3 = (int *)(**(code **)(local_450 + -0x54a8))();
        uVar12 = (uint)local_42c;
        uVar9 = uVar12 & 0xff;
        if ((*(ushort *)(*piVar3 + uVar9 * 2) & 0x20) == 0) goto LAB_0060c15c;
        param_2 = (char **)0x3;
      }
      unaff_s4 = (char **)0x0;
      ppcVar20 = unaff_s6;
      ppcVar21 = unaff_s6;
      puVar23 = local_450;
      if ((uVar9 < 0xe) && (iVar5 = local_43c, (0x2401U >> (uVar9 & 0x1f) & 1) != 0)) break;
      do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
        switch(param_2) {
        case (char **)0x1:
          param_3 = (char **)&DAT_0000003a;
          while (uVar12 != 0x3a) {
            while( true ) {
              ppcVar21 = (char **)((int)ppcVar21 + 1);
              uVar12 = (uint)*(char *)ppcVar21;
              param_2 = (char **)(uint)((uVar12 & 0xff) < 0xe);
              if (param_2 == (char **)0x0) break;
              unaff_s0 = ppcVar20;
              if ((0x2401U >> (uVar12 & 0x1f) & 1) != 0) goto LAB_0060bf34;
              if (uVar12 == 0x3a) goto LAB_0060c014;
            }
          }
LAB_0060c014:
          *(undefined *)ppcVar21 = 0;
          uVar12 = (uint)*(char *)ppcVar20;
          if (uVar12 == 0) {
LAB_0060c58c:
            unaff_s4 = (char **)0x0;
          }
          else {
            if (uVar12 != 0x22) {
              piVar3 = (int *)(**(code **)(puVar23 + -0x54a8))();
              param_3 = (char **)0x22;
              unaff_s4 = ppcVar20;
              do {
                ppcVar20 = (char **)((int)unaff_s4 + 1);
                puVar23 = local_450;
                if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) goto LAB_0060c07c;
                uVar12 = (uint)*(char *)ppcVar20;
                if (uVar12 == 0) goto LAB_0060c58c;
                unaff_s4 = ppcVar20;
              } while (uVar12 != 0x22);
            }
            unaff_s4 = (char **)((int)ppcVar20 + 1);
            if ((*(char *)((int)ppcVar20 + 1) == '\0') || (unaff_s4 == (char **)0x0))
            goto LAB_0060c58c;
LAB_0060c07c:
            iVar5 = (**(code **)(puVar23 + -0x53bc))(unaff_s4);
            ppcVar20 = (char **)((int)unaff_s4 + iVar5 + -1);
            puVar23 = local_450;
            if (ppcVar20 < unaff_s4) goto LAB_0060c58c;
            uVar12 = (uint)*(char *)ppcVar20;
            if (uVar12 != 0x22) {
              piVar3 = (int *)(**(code **)(local_450 + -0x54a8))();
              param_3 = (char **)0x22;
              iVar5 = *piVar3;
              do {
                puVar23 = local_450;
                if ((*(ushort *)(iVar5 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
                  cVar15 = *(char *)((int)ppcVar21 + 1);
                  goto LAB_0060bda0;
                }
                *(undefined *)ppcVar20 = 0;
                ppcVar20 = (char **)((int)ppcVar20 + -1);
                if (ppcVar20 < unaff_s4) goto LAB_0060c58c;
                uVar12 = (uint)*(char *)ppcVar20;
              } while (uVar12 != 0x22);
            }
            puVar23 = local_450;
            if (unaff_s4 == (char **)((int)ppcVar20 + -1)) goto LAB_0060c58c;
            *(undefined *)ppcVar20 = 0;
          }
          cVar15 = *(char *)((int)ppcVar21 + 1);
LAB_0060bda0:
          ppcVar20 = (char **)((int)ppcVar21 + 1);
          ppcVar13 = ppcVar20;
          unaff_s5 = ppcVar21;
          while( true ) {
            ppcVar21 = ppcVar13;
            uVar12 = (uint)cVar15;
            if (((uVar12 & 0xff) < 0xe) && ((0x2401U >> (uVar12 & 0x1f) & 1) != 0))
            goto LAB_0060bdf0;
LAB_0060bdb8:
            param_3 = (char **)0x28;
            if (uVar12 == 0x3b) {
              *(undefined *)ppcVar21 = 0;
              uVar12 = (uint)*(char *)ppcVar20;
              if (uVar12 == 0) goto LAB_0060c5e4;
              if (uVar12 == 0x22) goto LAB_0060c5cc;
              piVar3 = (int *)(**(code **)(puVar23 + -0x54a8))();
              ppcVar13 = ppcVar20;
              goto LAB_0060c268;
            }
            if (uVar12 == 0x28) break;
            cVar15 = *(char *)(char **)((int)ppcVar21 + 1);
            ppcVar13 = (char **)((int)ppcVar21 + 1);
          }
          uVar12 = (uint)*(char *)((int)ppcVar21 + 1);
          param_2 = (char **)(uint)((uVar12 & 0xff) < 0xe);
          ppcVar21 = (char **)((int)ppcVar21 + 1);
          if ((param_2 != (char **)0x0) && ((0x2401U >> (uVar12 & 0x1f) & 1) != 0)) {
            local_440 = (char **)&SUB_00000002;
            goto LAB_0060bd40;
          }
          param_2 = (char **)&SUB_00000002;
LAB_0060bf50:
          if (uVar12 != 0x29) {
            ppcVar21 = (char **)((int)ppcVar21 + 1);
            uVar12 = (uint)*(char *)ppcVar21;
            param_3 = (char **)(uint)((uVar12 & 0xff) < 0xe);
            if ((param_3 != (char **)0x0) &&
               (unaff_s7 = ppcVar21, unaff_s0 = ppcVar20, local_440 = param_2,
               (0x2401U >> (uVar12 & 0x1f) & 1) != 0)) goto joined_r0x0060bf80;
            goto LAB_0060bf50;
          }
          local_440 = param_2;
          break;
        case (char **)0x2:
          goto LAB_0060bdb8;
        case (char **)0x3:
          unaff_s5 = ppcVar21;
          goto LAB_0060bf08;
        }
        uVar12 = (uint)*(char *)((int)ppcVar21 + 1);
        param_3 = (char **)(uint)((uVar12 & 0xff) < 0xe);
        ppcVar21 = (char **)((int)ppcVar21 + 1);
      } while ((param_3 == (char **)0x0) || ((0x2401U >> (uVar12 & 0x1f) & 1) == 0));
      if (param_2 != (char **)&SUB_00000002) {
        if (param_2 == (char **)&SUB_00000004) {
LAB_0060bc40:
          uVar12 = (uint)*(char *)ppcVar20;
          if (uVar12 == 0) {
LAB_0060bd28:
            unaff_s5 = (char **)0x0;
          }
          else {
            if (uVar12 != 0x22) {
              piVar3 = (int *)(**(code **)(puVar23 + -0x54a8))();
              unaff_s5 = ppcVar20;
              do {
                ppcVar20 = (char **)((int)unaff_s5 + 1);
                if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
                  pcVar22 = *(code **)(local_450 + -0x53bc);
                  ppcVar20 = unaff_s5;
                  goto LAB_0060bca8;
                }
                uVar12 = (uint)*(char *)ppcVar20;
                if (uVar12 == 0) goto LAB_0060bd28;
                unaff_s5 = ppcVar20;
                puVar23 = local_450;
              } while (uVar12 != 0x22);
            }
            unaff_s5 = (char **)((int)ppcVar20 + 1);
            if (*(char *)((int)ppcVar20 + 1) == '\0') goto LAB_0060bd28;
            pcVar22 = *(code **)(puVar23 + -0x53bc);
            if (unaff_s5 != (char **)0x0) {
LAB_0060bca8:
              iVar5 = (*pcVar22)(unaff_s5);
              ppcVar13 = (char **)((int)unaff_s5 + iVar5 + -1);
              if (unaff_s5 <= ppcVar13) {
                ppcVar20 = (char **)(int)*(char *)ppcVar13;
                if (ppcVar20 == (char **)0x22) {
                  ppcVar4 = (char **)((int)ppcVar13 + -1);
                }
                else {
                  local_438 = ppcVar13;
                  piVar3 = (int *)(**(code **)(local_450 + -0x54a8))();
                  iVar5 = *piVar3;
                  ppcVar14 = local_438;
                  do {
                    if ((*(ushort *)(iVar5 + ((uint)ppcVar20 & 0xff) * 2) & 0x20) == 0)
                    goto LAB_0060bd2c;
                    *(undefined *)ppcVar14 = 0;
                    ppcVar13 = (char **)((int)ppcVar14 + -1);
                    if (ppcVar13 < unaff_s5) goto LAB_0060bd28;
                    ppcVar20 = (char **)(int)*(char *)ppcVar13;
                    ppcVar4 = (char **)((int)ppcVar14 + -2);
                    ppcVar14 = ppcVar13;
                  } while (ppcVar20 != (char **)0x22);
                }
                if (unaff_s5 != ppcVar4) {
                  *(undefined *)ppcVar13 = 0;
                  goto LAB_0060bd2c;
                }
              }
              goto LAB_0060bd28;
            }
            unaff_s5 = (char **)0x0;
          }
LAB_0060bd2c:
          param_2 = unaff_s4;
          param_3 = unaff_s5;
          mime_hdr_addparam_isra_1((char **)((int)unaff_s2 + 8));
          puVar23 = local_450;
LAB_0060bd40:
          pcVar22 = *(code **)(puVar23 + -0x790c);
          unaff_s0 = ppcVar20;
          unaff_s7 = ppcVar21;
        }
        else {
          pcVar22 = *(code **)(puVar23 + -0x790c);
          unaff_s0 = ppcVar20;
          unaff_s7 = ppcVar21;
        }
        goto joined_r0x0060bfc8;
      }
LAB_0060bdf0:
      uVar12 = (uint)*(char *)ppcVar20;
      if (uVar12 == 0) {
LAB_0060c5f8:
        unaff_s5 = (char **)0x0;
      }
      else {
        if (uVar12 != 0x22) {
          piVar3 = (int *)(**(code **)(puVar23 + -0x54a8))();
          unaff_s5 = ppcVar20;
          do {
            ppcVar20 = (char **)((int)unaff_s5 + 1);
            if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
              pcVar22 = *(code **)(local_450 + -0x53bc);
              goto LAB_0060be54;
            }
            uVar12 = (uint)*(char *)ppcVar20;
            unaff_s5 = (char **)0x0;
            if (uVar12 == 0) goto LAB_0060becc;
            unaff_s5 = ppcVar20;
            puVar23 = local_450;
          } while (uVar12 != 0x22);
        }
        if (*(char *)((int)ppcVar20 + 1) == '\0') goto LAB_0060c5f8;
        unaff_s5 = (char **)((int)ppcVar20 + 1);
        pcVar22 = *(code **)(puVar23 + -0x53bc);
        if (unaff_s5 != (char **)0x0) {
LAB_0060be54:
          iVar5 = (*pcVar22)(unaff_s5);
          ppcVar20 = (char **)((int)unaff_s5 + iVar5 + -1);
          if (unaff_s5 <= ppcVar20) {
            uVar12 = (uint)*(char *)ppcVar20;
            if (uVar12 != 0x22) {
              piVar3 = (int *)(**(code **)(local_450 + -0x54a8))();
              param_3 = (char **)0x22;
              iVar5 = *piVar3;
              do {
                if ((*(ushort *)(iVar5 + (uVar12 & 0xff) * 2) & 0x20) == 0) goto LAB_0060becc;
                *(undefined *)ppcVar20 = 0;
                ppcVar20 = (char **)((int)ppcVar20 + -1);
                if (ppcVar20 < unaff_s5) goto LAB_0060c5f8;
                uVar12 = (uint)*(char *)ppcVar20;
              } while (uVar12 != 0x22);
            }
            if (unaff_s5 != (char **)((int)ppcVar20 + -1)) {
              *(undefined *)ppcVar20 = 0;
              goto LAB_0060becc;
            }
          }
          goto LAB_0060c5f8;
        }
        unaff_s5 = (char **)0x0;
      }
LAB_0060becc:
      unaff_s2 = (char *)mime_hdr_new(unaff_s4,unaff_s5);
      param_2 = (char **)unaff_s2;
      (**(code **)(local_450 + -0x7e38))(local_43c);
      unaff_s7 = ppcVar21;
      puVar23 = local_450;
      unaff_s0 = ppcVar20;
joined_r0x0060bf80:
      iVar5 = local_43c;
    } while (unaff_s7 != unaff_s6);
  }
LAB_0060bd4c:
  if (local_2c == *local_434) {
    return iVar5;
  }
  pcStack_464 = SMIME_read_ASN1;
  iStack_4d0 = local_2c;
  (**(code **)(puVar23 + -0x5330))();
  puStack_4d4 = PTR___stack_chk_guard_006a9ae8;
  puStack_4a8 = &_gp;
  uStack_49c = 0;
  iStack_48c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_2 != (char **)0x0) {
    *param_2 = (char *)0x0;
  }
  ppcStack_488 = unaff_s0;
  puStack_484 = unaff_s1;
  ppcStack_480 = (char **)unaff_s2;
  ppuStack_47c = unaff_s3;
  ppcStack_478 = unaff_s4;
  ppcStack_474 = unaff_s5;
  ppcStack_470 = unaff_s6;
  ppcStack_46c = unaff_s7;
  uStack_468 = unaff_s8;
  iStack_4e8 = mime_parse_hdr(iStack_4d0);
  if (iStack_4e8 == 0) {
    pcVar22 = *(code **)(puStack_4a8 + -0x6eac);
    pBVar17 = (BIO *)0xcf;
    uStack_4b0 = 0x1b2;
    goto LAB_0060cc90;
  }
  unaff_s7 = apcStack_498;
  unaff_s2 = "content-type";
  apcStack_498[0] = "content-type";
  iVar5 = (**(code **)(puStack_4a8 + -0x6d9c))(iStack_4e8,unaff_s7);
  if ((iVar5 < 0) ||
     (unaff_s3 = (undefined **)(**(code **)(puStack_4a8 + -0x7fbc))(iStack_4e8,iVar5),
     unaff_s3 == (undefined **)0x0)) {
LAB_0060cc64:
    (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
    pBVar17 = (BIO *)0xd1;
    uStack_4b0 = 0x1b8;
    pcVar22 = *(code **)(puStack_4a8 + -0x6eac);
  }
  else {
    unaff_s1 = unaff_s3[1];
    if (unaff_s1 == (undefined *)0x0) goto LAB_0060cc64;
    iVar5 = (**(code **)(puStack_4a8 + -0x52c8))(unaff_s1,"multipart/signed");
    if (iVar5 != 0) {
      iVar5 = (**(code **)(puStack_4a8 + -0x52c8))(unaff_s1,"application/x-pkcs7-mime");
      if ((iVar5 == 0) ||
         (iVar5 = (**(code **)(puStack_4a8 + -0x52c8))(unaff_s1,"application/pkcs7-mime"),
         iVar5 == 0)) {
        (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
        uVar6 = (**(code **)(puStack_4a8 + -0x7924))();
        unaff_s1 = (undefined *)(**(code **)(puStack_4a8 + -0x7f3c))(uVar6);
        if (unaff_s1 == (undefined *)0x0) {
          uStack_4b0 = 0xba;
          (**(code **)(puStack_4a8 + -0x6eac))(0xd,0xd1,0x41,"asn_mime.c");
        }
        else {
          unaff_s2 = (char *)(**(code **)(puStack_4a8 + -0x791c))(unaff_s1,iStack_4d0);
          iVar5 = (**(code **)(puStack_4a8 + -0x7268))(param_3,unaff_s2,0);
          if (iVar5 != 0) {
            pcVar19 = (char *)0x0;
            pBVar17 = (BIO *)0x0;
            pcVar16 = (code *)&DAT_0000000b;
            (**(code **)(puStack_4a8 + -0x7fc8))(unaff_s2);
            (**(code **)(puStack_4a8 + -0x7418))(unaff_s2);
            (**(code **)(puStack_4a8 + -0x7f70))(unaff_s1);
            iStack_4e8 = iVar5;
            goto LAB_0060c8cc;
          }
          uStack_4b0 = 0xc0;
          (**(code **)(puStack_4a8 + -0x6eac))(0xd,0xd1,0x6e,"asn_mime.c");
          (**(code **)(puStack_4a8 + -0x7fc8))(unaff_s2,0xb,0,0);
          (**(code **)(puStack_4a8 + -0x7418))(unaff_s2);
          (**(code **)(puStack_4a8 + -0x7f70))(unaff_s1);
        }
        pcVar19 = "asn_mime.c";
        pBVar17 = (BIO *)0xcb;
        pcVar16 = (code *)&DAT_000000d4;
        uStack_4b0 = 0x205;
        (**(code **)(puStack_4a8 + -0x6eac))(0xd);
        iVar5 = 0;
        iStack_4e8 = 0x680000;
      }
      else {
        pcVar19 = "asn_mime.c";
        uStack_4b0 = 0x1fc;
        (**(code **)(puStack_4a8 + -0x6eac))(0xd,0xd4,0xcd);
        pBVar17 = (BIO *)unaff_s3[1];
        (**(code **)(puStack_4a8 + -0x6ca4))(2,"type: ");
        pcVar16 = mime_hdr_free;
        (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8);
        iVar5 = 0;
      }
      goto LAB_0060c8cc;
    }
    apcStack_498[0] = "boundary";
    iVar5 = (**(code **)(puStack_4a8 + -0x6d9c))(unaff_s3[2],unaff_s7);
    if (((-1 < iVar5) &&
        (iVar5 = (**(code **)(puStack_4a8 + -0x7fbc))(unaff_s3[2],iVar5), iVar5 != 0)) &&
       (*(int *)(iVar5 + 4) != 0)) {
      unaff_s3 = (undefined **)multi_split(iStack_4d0,*(int *)(iVar5 + 4),&uStack_49c);
      unaff_s1 = (undefined *)0x610000;
      (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
      if ((unaff_s3 == (undefined **)0x0) ||
         (iVar5 = (**(code **)(puStack_4a8 + -0x7fb4))(uStack_49c), iVar5 != 2)) {
        pcVar22 = *(code **)(puStack_4a8 + -0x6eac);
        pBVar17 = (BIO *)0xd2;
        uStack_4b0 = 0x1c9;
LAB_0060cb48:
        pcVar19 = "asn_mime.c";
        (*pcVar22)(0xd,0xd4);
      }
      else {
        unaff_s3 = (undefined **)(**(code **)(puStack_4a8 + -0x7fbc))(uStack_49c,1);
        iStack_4e8 = mime_parse_hdr(unaff_s3);
        if (iStack_4e8 == 0) {
          pcVar22 = *(code **)(puStack_4a8 + -0x6eac);
          pBVar17 = (BIO *)&DAT_000000d0;
          uStack_4b0 = 0x1d2;
          goto LAB_0060cb48;
        }
        apcStack_498[0] = "content-type";
        iVar5 = (**(code **)(puStack_4a8 + -0x6d9c))(iStack_4e8,unaff_s7);
        if (((iVar5 < 0) ||
            (iStack_4d0 = (**(code **)(puStack_4a8 + -0x7fbc))(iStack_4e8,iVar5), iStack_4d0 == 0))
           || (unaff_s2 = *(char **)(iStack_4d0 + 4), (char **)unaff_s2 == (char **)0x0)) {
          (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
          pBVar17 = (BIO *)&DAT_000000d4;
          uStack_4b0 = 0x1db;
          pcVar22 = *(code **)(puStack_4a8 + -0x6eac);
          goto LAB_0060cc90;
        }
        iVar5 = (**(code **)(puStack_4a8 + -0x52c8))(unaff_s2,"application/x-pkcs7-signature");
        if ((iVar5 == 0) ||
           (iVar5 = (**(code **)(puStack_4a8 + -0x52c8))(unaff_s2,"application/pkcs7-signature"),
           iVar5 == 0)) {
          (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
          uVar6 = (**(code **)(puStack_4a8 + -0x7924))();
          unaff_s2 = (char *)(**(code **)(puStack_4a8 + -0x7f3c))(uVar6);
          if ((char **)unaff_s2 == (char **)0x0) {
            uStack_4b0 = 0xba;
            (**(code **)(puStack_4a8 + -0x6eac))(0xd,0xd1,0x41,"asn_mime.c");
          }
          else {
            unaff_s1 = (undefined *)(**(code **)(puStack_4a8 + -0x791c))(unaff_s2,unaff_s3);
            iVar5 = (**(code **)(puStack_4a8 + -0x7268))(param_3,unaff_s1,0);
            if (iVar5 != 0) {
              pcVar19 = (char *)0x0;
              pBVar17 = (BIO *)0x0;
              (**(code **)(puStack_4a8 + -0x7fc8))(unaff_s1,0xb);
              (**(code **)(puStack_4a8 + -0x7418))(unaff_s1);
              (**(code **)(puStack_4a8 + -0x7f70))(unaff_s2);
              iStack_4e8 = iVar5;
              if (param_2 == (char **)0x0) {
                pcVar16 = *(code **)(puStack_4a8 + -0x55ec);
                (**(code **)(puStack_4a8 + -0x7d88))(uStack_49c);
              }
              else {
                pcVar16 = (code *)0x0;
                pcVar10 = (char *)(**(code **)(puStack_4a8 + -0x7fbc))(uStack_49c);
                pcVar22 = *(code **)(puStack_4a8 + -0x7f70);
                *param_2 = pcVar10;
                (*pcVar22)(unaff_s3);
                (**(code **)(puStack_4a8 + -0x7f60))(uStack_49c);
              }
              goto LAB_0060c8cc;
            }
            uStack_4b0 = 0xc0;
            (**(code **)(puStack_4a8 + -0x6eac))(0xd,0xd1,0x6e,"asn_mime.c");
            (**(code **)(puStack_4a8 + -0x7fc8))(unaff_s1,0xb,0,0);
            (**(code **)(puStack_4a8 + -0x7418))(unaff_s1);
            (**(code **)(puStack_4a8 + -0x7f70))(unaff_s2);
          }
          iStack_4e8 = 0x680000;
          pcVar22 = *(code **)(puStack_4a8 + -0x6eac);
          pBVar17 = (BIO *)&DAT_000000cc;
          uStack_4b0 = 0x1ea;
          goto LAB_0060cb48;
        }
        pcVar19 = "asn_mime.c";
        uStack_4b0 = 0x1e1;
        (**(code **)(puStack_4a8 + -0x6eac))(0xd,0xd4,0xd5);
        pBVar17 = *(BIO **)(iStack_4d0 + 4);
        (**(code **)(puStack_4a8 + -0x6ca4))(2,"type: ");
        (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
      }
      pcVar16 = *(code **)(puStack_4a8 + -0x55ec);
      (**(code **)(puStack_4a8 + -0x7d88))(uStack_49c);
      iVar5 = 0;
      goto LAB_0060c8cc;
    }
    (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
    pBVar17 = (BIO *)0xd3;
    uStack_4b0 = 0x1c3;
    pcVar22 = *(code **)(puStack_4a8 + -0x6eac);
  }
LAB_0060cc90:
  pcVar19 = "asn_mime.c";
  pcVar16 = (code *)&DAT_000000d4;
  (*pcVar22)(0xd);
  iVar5 = 0;
LAB_0060c8cc:
  if (iStack_48c == *(int *)puStack_4d4) {
    return iVar5;
  }
  pcStack_4c4 = SMIME_crlf_copy;
  iVar5 = iStack_48c;
  (**(code **)(puStack_4a8 + -0x5330))();
  puVar23 = PTR___stack_chk_guard_006a9ae8;
  pBStack_4ec = *(BIO **)PTR___stack_chk_guard_006a9ae8;
  val = (ASN1_VALUE *)pcVar16;
  pBVar18 = pBVar17;
  puStack_4e4 = unaff_s1;
  ppcStack_4e0 = (char **)unaff_s2;
  ppuStack_4dc = unaff_s3;
  ppcStack_4d8 = param_2;
  ppcStack_4cc = unaff_s7;
  ppcStack_4c8 = param_3;
  uVar6 = (*(code *)PTR_BIO_f_buffer_006a7854)();
  iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar6);
  if (iVar2 == 0) {
    iVar5 = 0;
  }
  else {
    uVar6 = (*(code *)PTR_BIO_push_006a74c4)(iVar2,pcVar16);
    if (((uint)pBVar17 & 0x80) == 0) {
      if (((uint)pBVar17 & 1) != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(uVar6,"Content-Type: text/plain\r\n\r\n");
      }
      pcVar19 = acStack_8ee + 2;
LAB_0060cf58:
      iVar7 = (*(code *)PTR_BIO_gets_006a74d4)(iVar5,pcVar19,0x400);
      if (0 < iVar7) {
        do {
          iVar8 = iVar7 + -1;
          pcVar10 = pcVar19 + iVar7 + -2;
          bVar1 = false;
          cVar15 = acStack_8ee[iVar7 + 1];
          if (cVar15 == '\n') goto LAB_0060cfac;
          while (cVar15 == '\r') {
            iVar7 = iVar8;
            pcVar11 = pcVar10;
            if (iVar8 == 0) goto LAB_0060cfd0;
            while( true ) {
              pcVar10 = pcVar11 + -1;
              iVar8 = iVar7 + -1;
              cVar15 = *pcVar11;
              if (cVar15 != '\n') break;
LAB_0060cfac:
              bVar1 = true;
              iVar7 = iVar8;
              pcVar11 = pcVar10;
              if (iVar8 == 0) goto LAB_0060cfd8;
            }
          }
          (*(code *)PTR_BIO_write_006a6e14)(uVar6,pcVar19,iVar7);
LAB_0060cfd0:
          if (!bVar1) goto LAB_0060cf58;
LAB_0060cfd8:
          (*(code *)PTR_BIO_write_006a6e14)(uVar6,"\r\n",2);
          iVar7 = (*(code *)PTR_BIO_gets_006a74d4)(iVar5,pcVar19,0x400);
          if (iVar7 < 1) break;
        } while( true );
      }
    }
    else {
      while (iVar7 = (*(code *)PTR_BIO_read_006a74c0)(iVar5,acStack_8ee + 2,0x400), 0 < iVar7) {
        (*(code *)PTR_BIO_write_006a6e14)(uVar6,acStack_8ee + 2,iVar7);
      }
    }
    pcVar19 = (char *)0x0;
    pBVar18 = (BIO *)0x0;
    val = (ASN1_VALUE *)&DAT_0000000b;
    (*(code *)PTR_BIO_ctrl_006a6e18)(uVar6);
    (*(code *)PTR_BIO_pop_006a79c8)(uVar6);
    (*(code *)PTR_BIO_free_006a6e70)(iVar2);
    iVar5 = 1;
  }
  if (pBStack_4ec == *(BIO **)puVar23) {
    return iVar5;
  }
  pBVar17 = pBStack_4ec;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (((uint)pcVar19 & 0x1000) == 0) {
    (*(code *)PTR_ASN1_item_i2d_bio_006a7720)(&_gp,pBVar17,val);
    iVar5 = 1;
  }
  else {
    out = BIO_new_NDEF(pBVar17,val,(ASN1_ITEM *)&_gp);
    if (out != (BIO *)0x0) {
      SMIME_crlf_copy(pBVar18,out,(int)pcVar19);
      (*(code *)PTR_BIO_ctrl_006a6e18)(out,0xb,0,0);
      do {
        pBVar18 = (BIO *)(*(code *)PTR_BIO_pop_006a79c8)(out);
        (*(code *)PTR_BIO_free_006a6e70)(out);
        out = pBVar18;
      } while (pBVar17 != pBVar18);
      return 1;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xd3,0x41,"asn_mime.c",0x7d);
    iVar5 = 0;
  }
  return iVar5;
  while( true ) {
    uVar12 = (uint)*(char *)ppcVar20;
    ppcVar13 = (char **)0x0;
    if (uVar12 == 0) goto LAB_0060c304;
    ppcVar13 = ppcVar20;
    puVar23 = local_450;
    if (uVar12 == 0x22) break;
LAB_0060c268:
    ppcVar20 = (char **)((int)ppcVar13 + 1);
    if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
      pcVar22 = *(code **)(local_450 + -0x53bc);
      goto LAB_0060c28c;
    }
  }
LAB_0060c5cc:
  ppcVar13 = (char **)0x0;
  if (*(char *)((int)ppcVar20 + 1) != '\0') {
    ppcVar13 = (char **)((int)ppcVar20 + 1);
    pcVar22 = *(code **)(puVar23 + -0x53bc);
    if (ppcVar13 != (char **)0x0) {
LAB_0060c28c:
      iVar5 = (*pcVar22)(ppcVar13);
      ppcVar20 = (char **)((int)ppcVar13 + iVar5 + -1);
      if (ppcVar13 <= ppcVar20) {
        uVar12 = (uint)*(char *)ppcVar20;
        if (uVar12 != 0x22) {
          piVar3 = (int *)(**(code **)(local_450 + -0x54a8))();
          iVar5 = *piVar3;
          do {
            if ((*(ushort *)(iVar5 + (uVar12 & 0xff) * 2) & 0x20) == 0) goto LAB_0060c304;
            *(undefined *)ppcVar20 = 0;
            ppcVar20 = (char **)((int)ppcVar20 + -1);
            if (ppcVar20 < ppcVar13) goto LAB_0060c5e4;
            uVar12 = (uint)*(char *)ppcVar20;
          } while (uVar12 != 0x22);
        }
        if (ppcVar13 != (char **)((int)ppcVar20 + -1)) {
          *(undefined *)ppcVar20 = 0;
          goto LAB_0060c304;
        }
      }
    }
LAB_0060c5e4:
    ppcVar13 = (char **)0x0;
  }
LAB_0060c304:
  unaff_s2 = (char *)mime_hdr_new(unaff_s4,ppcVar13);
  unaff_s5 = (char **)((int)ppcVar21 + 1);
  param_2 = (char **)unaff_s2;
  (**(code **)(local_450 + -0x7e38))(local_43c);
LAB_0060c330:
  do {
    cVar15 = *(char *)((int)ppcVar21 + 1);
    unaff_s0 = ppcVar20;
    ppcVar20 = unaff_s5;
    puVar23 = local_450;
    while( true ) {
      uVar12 = (uint)cVar15;
      if (((uVar12 & 0xff) < 0xe) && (ppcVar21 = unaff_s5, (0x2401U >> (uVar12 & 0x1f) & 1) != 0))
      goto LAB_0060bf34;
LAB_0060bf08:
      param_2 = (char **)&DAT_0000003d;
      if (uVar12 == 0x3d) break;
      unaff_s5 = (char **)((int)unaff_s5 + 1);
      cVar15 = *(char *)unaff_s5;
      unaff_s0 = ppcVar20;
    }
    *(undefined *)unaff_s5 = 0;
    uVar12 = (uint)*(char *)ppcVar20;
    if (uVar12 == 0) {
LAB_0060c584:
      unaff_s4 = (char **)0x0;
    }
    else {
      if (uVar12 != 0x22) {
        piVar3 = (int *)(**(code **)(puVar23 + -0x54a8))();
        unaff_s4 = ppcVar20;
        do {
          ppcVar20 = (char **)((int)unaff_s4 + 1);
          puVar23 = local_450;
          if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) goto LAB_0060c4e0;
          uVar12 = (uint)*(char *)ppcVar20;
          if (uVar12 == 0) goto LAB_0060c584;
          unaff_s4 = ppcVar20;
        } while (uVar12 != 0x22);
      }
      unaff_s4 = (char **)((int)ppcVar20 + 1);
      if ((*(char *)((int)ppcVar20 + 1) == '\0') || (unaff_s4 == (char **)0x0)) goto LAB_0060c584;
LAB_0060c4e0:
      iVar5 = (**(code **)(puVar23 + -0x53bc))(unaff_s4);
      ppcVar21 = (char **)((int)unaff_s4 + iVar5 + -1);
      puVar23 = local_450;
      if (ppcVar21 < unaff_s4) goto LAB_0060c584;
      uVar12 = (uint)*(char *)ppcVar21;
      if (uVar12 != 0x22) {
        piVar3 = (int *)(**(code **)(local_450 + -0x54a8))();
        iVar5 = *piVar3;
        do {
          puVar23 = local_450;
          if ((*(ushort *)(iVar5 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
            cVar15 = *(char *)((int)unaff_s5 + 1);
            goto LAB_0060bbe4;
          }
          *(undefined *)ppcVar21 = 0;
          ppcVar21 = (char **)((int)ppcVar21 + -1);
          if (ppcVar21 < unaff_s4) goto LAB_0060c584;
          uVar12 = (uint)*(char *)ppcVar21;
        } while (uVar12 != 0x22);
      }
      puVar23 = local_450;
      if (unaff_s4 == (char **)((int)ppcVar21 + -1)) goto LAB_0060c584;
      *(undefined *)ppcVar21 = 0;
    }
    cVar15 = *(char *)((int)unaff_s5 + 1);
LAB_0060bbe4:
    ppcVar20 = (char **)((int)unaff_s5 + 1);
    ppcVar21 = ppcVar20;
    while( true ) {
      uVar12 = (uint)cVar15;
      if (((uVar12 & 0xff) < 0xe) && ((0x2401U >> (uVar12 & 0x1f) & 1) != 0)) goto LAB_0060bc40;
      param_3 = (char **)0x28;
      if (uVar12 == 0x3b) break;
      if (uVar12 == 0x22) {
        cVar15 = *(char *)((int)ppcVar21 + 1);
        unaff_s7 = (char **)((int)ppcVar21 + 1);
        while( true ) {
          uVar12 = (uint)cVar15;
          param_2 = (char **)(uint)((uVar12 & 0xff) < 0xe);
          if ((param_2 != (char **)0x0) && ((0x2401U >> (uVar12 & 0x1f) & 1) != 0)) {
            pcVar22 = *(code **)(puVar23 + -0x790c);
            unaff_s0 = ppcVar20;
            goto joined_r0x0060bfc8;
          }
          param_3 = (char **)0x22;
          if (uVar12 == 0x22) break;
          unaff_s7 = (char **)((int)unaff_s7 + 1);
          cVar15 = *(char *)unaff_s7;
        }
        cVar15 = *(char *)((int)unaff_s7 + 1);
        ppcVar21 = (char **)((int)unaff_s7 + 1);
      }
      else {
        if (uVar12 == 0x28) {
          uVar12 = (uint)*(char *)((int)ppcVar21 + 1);
          param_2 = (char **)(uint)((uVar12 & 0xff) < 0xe);
          ppcVar21 = (char **)((int)ppcVar21 + 1);
          if ((param_2 != (char **)0x0) && ((0x2401U >> (uVar12 & 0x1f) & 1) != 0)) {
            local_440 = (char **)&SUB_00000004;
            goto LAB_0060bd40;
          }
          param_2 = (char **)&SUB_00000004;
          goto LAB_0060bf50;
        }
        cVar15 = *(char *)(char **)((int)ppcVar21 + 1);
        ppcVar21 = (char **)((int)ppcVar21 + 1);
      }
    }
    *(undefined *)ppcVar21 = 0;
    uVar12 = (uint)*(char *)ppcVar20;
    param_2 = unaff_s4;
    if (uVar12 == 0) goto LAB_0060c5b0;
    if (uVar12 != 0x22) {
      piVar3 = (int *)(**(code **)(puVar23 + -0x54a8))();
      do {
        ppcVar13 = (char **)((int)ppcVar20 + 1);
        if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
          pcVar22 = *(code **)(local_450 + -0x53bc);
          param_3 = ppcVar20;
          goto LAB_0060c3c8;
        }
        uVar12 = (uint)*(char *)ppcVar13;
        ppcVar20 = ppcVar13;
        if (uVar12 == 0) goto LAB_0060c5b0;
        puVar23 = local_450;
      } while (uVar12 != 0x22);
    }
    if (*(char *)((int)ppcVar20 + 1) == '\0') goto LAB_0060c5b0;
    param_3 = (char **)((int)ppcVar20 + 1);
    pcVar22 = *(code **)(puVar23 + -0x53bc);
    if (param_3 == (char **)0x0) goto LAB_0060c5b0;
LAB_0060c3c8:
    iVar5 = (*pcVar22)(param_3);
    ppcVar13 = (char **)((int)param_3 + iVar5 + -1);
    if (ppcVar13 < param_3) goto LAB_0060c5b0;
    ppcVar20 = (char **)(int)*(char *)ppcVar13;
    if (ppcVar20 == (char **)0x22) {
      ppcVar4 = (char **)((int)ppcVar13 + -1);
    }
    else {
      local_438 = ppcVar13;
      piVar3 = (int *)(**(code **)(local_450 + -0x54a8))();
      iVar5 = *piVar3;
      ppcVar14 = local_438;
      do {
        if ((*(ushort *)(iVar5 + ((uint)ppcVar20 & 0xff) * 2) & 0x20) == 0) {
          mime_hdr_addparam_isra_1((char **)((int)unaff_s2 + 8));
          unaff_s5 = (char **)((int)ppcVar21 + 1);
          goto LAB_0060c330;
        }
        *(undefined *)ppcVar14 = 0;
        ppcVar13 = (char **)((int)ppcVar14 + -1);
        if (ppcVar13 < param_3) goto LAB_0060c5b0;
        ppcVar20 = (char **)(int)*(char *)ppcVar13;
        ppcVar4 = (char **)((int)ppcVar14 + -2);
        ppcVar14 = ppcVar13;
      } while (ppcVar20 != (char **)0x22);
    }
    if (param_3 == ppcVar4) {
LAB_0060c5b0:
      param_3 = (char **)0x0;
      mime_hdr_addparam_isra_1((char **)((int)unaff_s2 + 8));
      unaff_s5 = (char **)((int)ppcVar21 + 1);
    }
    else {
      *(undefined *)ppcVar13 = 0;
      mime_hdr_addparam_isra_1((char **)((int)unaff_s2 + 8));
      unaff_s5 = (char **)((int)ppcVar21 + 1);
    }
  } while( true );
LAB_0060bf34:
  pcVar22 = *(code **)(puVar23 + -0x790c);
  unaff_s5 = ppcVar21;
  unaff_s7 = ppcVar21;
joined_r0x0060bfc8:
  iVar5 = local_43c;
  if (unaff_s7 == unaff_s6) goto LAB_0060bd4c;
  goto LAB_0060bb3c;
}

