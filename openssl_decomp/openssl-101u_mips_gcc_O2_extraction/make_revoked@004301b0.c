
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int make_revoked(int param_1)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  char *pcVar18;
  undefined4 uVar19;
  uint uVar20;
  int *piVar21;
  char **ppcVar22;
  byte *pbVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  undefined4 *puVar27;
  int iVar28;
  undefined *puVar29;
  undefined4 uVar30;
  int iVar31;
  undefined4 uVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  byte *pbVar38;
  undefined4 *puVar39;
  undefined4 *puVar40;
  undefined4 *******pppppppuVar41;
  undefined4 uVar42;
  undefined4 ******ppppppuVar43;
  undefined1 *puVar44;
  uint *puVar45;
  undefined4 uVar46;
  char *pcVar47;
  int iVar48;
  undefined *puVar49;
  undefined *puVar50;
  undefined4 ******ppppppuVar51;
  undefined4 *******pppppppuVar52;
  code *pcVar53;
  int iStack_494;
  int iStack_48c;
  undefined4 ******ppppppuStack_488;
  undefined4 ******ppppppuStack_480;
  int iStack_47c;
  int iStack_478;
  int iStack_474;
  int iStack_470;
  int iStack_46c;
  int iStack_468;
  int iStack_460;
  undefined4 ******ppppppuStack_45c;
  undefined4 uStack_458;
  char *pcStack_454;
  undefined4 ******ppppppuStack_450;
  undefined4 ******ppppppuStack_44c;
  undefined4 ******ppppppuStack_448;
  undefined4 ******ppppppuStack_43c;
  undefined4 ******ppppppuStack_438;
  int iStack_434;
  undefined4 ******ppppppuStack_430;
  undefined4 ******ppppppuStack_42c;
  undefined4 ******ppppppuStack_428;
  undefined4 ******ppppppuStack_424;
  undefined4 uStack_420;
  undefined4 ******ppppppuStack_41c;
  int iStack_418;
  undefined4 ******ppppppuStack_410;
  undefined4 ******ppppppuStack_40c;
  undefined4 ******ppppppuStack_408;
  undefined4 ******ppppppuStack_404;
  int iStack_400;
  undefined4 ******ppppppuStack_3fc;
  int iStack_3f4;
  undefined4 uStack_3f0;
  undefined4 ******ppppppuStack_3bc;
  int iStack_3b8;
  int iStack_3b4;
  int iStack_3b0;
  int iStack_3ac;
  undefined4 ******ppppppuStack_3a8;
  undefined4 uStack_3a4;
  undefined4 uStack_3a0;
  undefined4 uStack_39c;
  int *piStack_398;
  undefined4 uStack_394;
  undefined4 auStack_390 [7];
  uint auStack_374 [3];
  char *pcStack_368;
  undefined4 uStack_364;
  undefined4 uStack_360;
  uint auStack_35c [122];
  undefined auStack_174 [256];
  int iStack_74;
  undefined *puStack_70;
  int iStack_6c;
  int iStack_68;
  undefined4 *******local_24;
  int local_20;
  int local_1c;
  undefined4 *******local_18;
  int local_14;
  
  puStack_70 = PTR___stack_chk_guard_006a9ae8;
  pppppppuVar41 = &local_24;
  local_20 = 0;
  local_24 = (undefined4 *******)0xffffffff;
  local_1c = 0;
  local_18 = (undefined4 *******)0x0;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar14 = unpack_revinfo(&local_18,pppppppuVar41,&local_20,&local_1c);
  if (iVar14 == 0) {
LAB_00430278:
    iStack_68 = 0;
    iStack_6c = 0;
  }
  else {
    if (param_1 == 0) {
      iStack_68 = 0;
      goto LAB_004302f4;
    }
    pppppppuVar41 = local_18;
    iVar14 = (*(code *)PTR_X509_REVOKED_set_revocationDate_006a7040)(param_1);
    if (iVar14 == 0) goto LAB_00430278;
    if (local_24 == (undefined4 *******)0xffffffff) {
      iStack_68 = 0;
LAB_00430310:
      if (local_1c != 0) {
        pppppppuVar41 = (undefined4 *******)0x8e;
        iVar14 = (*(code *)PTR_X509_REVOKED_add1_ext_i2d_006a7054)(param_1,0x8e,local_1c,0);
        if (iVar14 == 0) goto LAB_0043026c;
      }
      if (local_20 != 0) {
        pppppppuVar41 = (undefined4 *******)&DAT_000001ae;
        iVar14 = (*(code *)PTR_X509_REVOKED_add1_ext_i2d_006a7054)(param_1,0x1ae,local_20,0);
        if (iVar14 == 0) {
          iStack_6c = 0;
          goto LAB_00430284;
        }
      }
LAB_004302f4:
      iStack_6c = 1;
      if (local_24 != (undefined4 *******)0xffffffff) {
        iStack_6c = 2;
      }
    }
    else {
      iStack_68 = (*(code *)PTR_ASN1_ENUMERATED_new_006a7044)();
      if ((iStack_68 == 0) ||
         (pppppppuVar41 = local_24, iVar14 = (*(code *)PTR_ASN1_ENUMERATED_set_006a7048)(iStack_68),
         iVar14 == 0)) {
LAB_0043026c:
        iStack_6c = 0;
      }
      else {
        pppppppuVar41 = (undefined4 *******)0x8d;
        iVar14 = (*(code *)PTR_X509_REVOKED_add1_ext_i2d_006a7054)(param_1,0x8d,iStack_68,0);
        if (iVar14 != 0) goto LAB_00430310;
        iStack_6c = 0;
      }
    }
  }
LAB_00430284:
  (*(code *)PTR_ASN1_OBJECT_free_006a7004)(local_20);
  (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(local_1c);
  (*(code *)PTR_ASN1_ENUMERATED_free_006a704c)(iStack_68);
  (*(code *)PTR_ASN1_TIME_free_006a7050)(local_18);
  if (local_14 == *(int *)puStack_70) {
    return iStack_6c;
  }
  iVar14 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar11 = PTR___stack_chk_guard_006a9ae8;
  puVar10 = PTR_bio_err_006a6e3c;
  iStack_3b0 = -1;
  ppppppuStack_3bc = (undefined4 ******)0x0;
  iStack_3b8 = 0;
  iStack_3b4 = 0;
  iStack_3ac = 0;
  ppppppuStack_3a8 = (undefined4 ******)0x0;
  uStack_3a4 = 0;
  uStack_3a0 = 0;
  uStack_39c = 0;
  piStack_398 = (int *)0x0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  ppppppuStack_3bc = (undefined4 ******)0x0;
  conf = 0;
  section = (undefined4 ******)0x0;
  preserve = 0;
  msie_hack = 0;
  if (*(int *)puVar10 == 0) {
    uVar16 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar48 = (*(code *)PTR_BIO_new_006a6ea4)(uVar16);
    *(int *)puVar10 = iVar48;
    if (iVar48 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar48,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
    }
  }
  iVar14 = iVar14 + -1;
  ppppppuStack_480 = (undefined4 ******)0x0;
  pppppppuVar41 = pppppppuVar41 + 1;
  if (iVar14 < 1) {
    iStack_418 = 0;
    bVar8 = false;
    ppppppuVar51 = (undefined4 ******)0x0;
    iStack_434 = 0;
    iVar48 = 0;
    iStack_46c = 0x1001;
    ppppppuStack_450 = (undefined4 ******)0x0;
    pcStack_454 = (char *)0x0;
    uStack_3f0 = 3;
    ppppppuStack_41c = (undefined4 ******)0x0;
    uStack_420 = 0;
    ppppppuStack_438 = (undefined4 ******)0x0;
    uStack_458 = 0;
    ppppppuStack_488 = (undefined4 ******)0x0;
    ppppppuStack_428 = (undefined4 ******)0x0;
    ppppppuStack_45c = (undefined4 ******)0x0;
    ppppppuStack_44c = (undefined4 ******)0x0;
    ppppppuStack_408 = (undefined4 ******)0x0;
    ppppppuStack_42c = (undefined4 ******)0x0;
    ppppppuStack_404 = (undefined4 ******)0x0;
    ppppppuStack_430 = (undefined4 ******)0x0;
    ppppppuStack_424 = (undefined4 ******)0x0;
    ppppppuStack_40c = (undefined4 ******)0x0;
    ppppppuStack_410 = (undefined4 ******)0x0;
    ppppppuStack_448 = (undefined4 ******)0x0;
    ppppppuStack_43c = (undefined4 ******)0x0;
    iStack_400 = 0;
    bVar7 = false;
    bVar9 = false;
    bVar6 = false;
    bVar4 = true;
    iStack_460 = 0;
    ppppppuStack_3fc = (undefined4 ******)0x0;
    iStack_468 = 0;
    bVar3 = false;
  }
  else {
    iStack_468 = 0;
    iStack_418 = 0;
    bVar8 = false;
    iStack_46c = 0x1001;
    iStack_434 = 0;
    ppppppuVar51 = (undefined4 ******)0x0;
    ppppppuStack_450 = (undefined4 ******)0x0;
    iVar48 = 0;
    uStack_3f0 = 3;
    pcStack_454 = (char *)0x0;
    ppppppuStack_41c = (undefined4 ******)0x0;
    bVar4 = true;
    uStack_420 = 0;
    ppppppuStack_438 = (undefined4 ******)0x0;
    uStack_458 = 0;
    ppppppuStack_488 = (undefined4 ******)0x0;
    ppppppuStack_428 = (undefined4 ******)0x0;
    ppppppuStack_45c = (undefined4 ******)0x0;
    ppppppuStack_44c = (undefined4 ******)0x0;
    ppppppuStack_408 = (undefined4 ******)0x0;
    ppppppuStack_42c = (undefined4 ******)0x0;
    ppppppuStack_404 = (undefined4 ******)0x0;
    ppppppuStack_430 = (undefined4 ******)0x0;
    ppppppuStack_424 = (undefined4 ******)0x0;
    ppppppuStack_40c = (undefined4 ******)0x0;
    ppppppuStack_410 = (undefined4 ******)0x0;
    ppppppuStack_448 = (undefined4 ******)0x0;
    ppppppuStack_43c = (undefined4 ******)0x0;
    iStack_400 = 0;
    bVar7 = false;
    bVar9 = false;
    bVar6 = false;
    bVar3 = false;
    iStack_460 = 0;
    ppppppuStack_3fc = (undefined4 ******)0x0;
    do {
      while( true ) {
        ppppppuVar43 = *pppppppuVar41;
        iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-verbose");
        if (iVar15 != 0) break;
        iVar14 = iVar14 + -1;
        iVar48 = 1;
        pppppppuVar41 = pppppppuVar41 + 1;
        if (iVar14 == 0) goto LAB_004305cc;
      }
      iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-config");
      if (iVar15 == 0) {
        iVar14 = iVar14 + -1;
        if (iVar14 == 0) goto LAB_00430988;
        ppppppuVar51 = pppppppuVar41[1];
        pppppppuVar52 = pppppppuVar41 + 1;
      }
      else {
        iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-name");
        if (iVar15 == 0) {
          iVar14 = iVar14 + -1;
          if (iVar14 == 0) goto LAB_00430988;
          section = pppppppuVar41[1];
          pppppppuVar52 = pppppppuVar41 + 1;
        }
        else {
          iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-subj");
          if (iVar15 == 0) {
            iVar14 = iVar14 + -1;
            if (iVar14 == 0) goto LAB_00430988;
            ppppppuStack_488 = pppppppuVar41[1];
            pppppppuVar52 = pppppppuVar41 + 1;
          }
          else {
            iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-utf8");
            pppppppuVar52 = pppppppuVar41;
            if (iVar15 == 0) {
              iStack_46c = 0x1000;
            }
            else {
              iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-create_serial");
              if (iVar15 == 0) {
                iStack_460 = 1;
              }
              else {
                iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-multivalue-rdn");
                if (iVar15 == 0) {
                  uStack_458 = 1;
                }
                else {
                  iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-startdate");
                  if (iVar15 == 0) {
                    iVar14 = iVar14 + -1;
                    if (iVar14 == 0) goto LAB_00430988;
                    pcStack_454 = (char *)pppppppuVar41[1];
                    pppppppuVar52 = pppppppuVar41 + 1;
                  }
                  else {
                    iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-enddate");
                    if (iVar15 == 0) {
                      iVar14 = iVar14 + -1;
                      if (iVar14 == 0) goto LAB_00430988;
                      ppppppuStack_450 = pppppppuVar41[1];
                      pppppppuVar52 = pppppppuVar41 + 1;
                    }
                    else {
                      iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-days");
                      if (iVar15 == 0) {
                        iVar14 = iVar14 + -1;
                        if (iVar14 == 0) goto LAB_00430988;
                        ppppppuStack_3a8 =
                             (undefined4 ******)
                             (*(code *)PTR_strtol_006a9958)(pppppppuVar41[1],0,10);
                        pppppppuVar52 = pppppppuVar41 + 1;
                      }
                      else {
                        cVar1 = *(char *)ppppppuVar43;
                        if ((((cVar1 == '-') && (*(char *)((int)ppppppuVar43 + 1) == 'm')) &&
                            (*(char *)((int)ppppppuVar43 + 2) == 'd')) &&
                           (*(char *)((int)ppppppuVar43 + 3) == '\0')) {
                          iVar14 = iVar14 + -1;
                          if (iVar14 == 0) goto LAB_00430988;
                          ppppppuStack_43c = pppppppuVar41[1];
                          pppppppuVar52 = pppppppuVar41 + 1;
                        }
                        else {
                          iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-policy");
                          if (iVar15 == 0) {
                            iVar14 = iVar14 + -1;
                            if (iVar14 == 0) goto LAB_00430988;
                            ppppppuStack_448 = pppppppuVar41[1];
                            pppppppuVar52 = pppppppuVar41 + 1;
                          }
                          else {
                            iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-keyfile");
                            if (iVar15 == 0) {
                              iVar14 = iVar14 + -1;
                              if (iVar14 == 0) goto LAB_00430988;
                              ppppppuStack_410 = pppppppuVar41[1];
                              pppppppuVar52 = pppppppuVar41 + 1;
                            }
                            else {
                              iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-keyform");
                              if (iVar15 == 0) {
                                iVar14 = iVar14 + -1;
                                if (iVar14 == 0) goto LAB_00430988;
                                uStack_3f0 = (*(code *)PTR_str2fmt_006a6e4c)(pppppppuVar41[1]);
                                pppppppuVar52 = pppppppuVar41 + 1;
                              }
                              else {
                                iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-passin");
                                if (iVar15 == 0) {
                                  iVar14 = iVar14 + -1;
                                  if (iVar14 == 0) goto LAB_00430988;
                                  ppppppuStack_3fc = pppppppuVar41[1];
                                  pppppppuVar52 = pppppppuVar41 + 1;
                                }
                                else {
                                  iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                     (ppppppuVar43,&DAT_006326ec);
                                  if (iVar15 == 0) {
                                    iVar14 = iVar14 + -1;
                                    if (iVar14 == 0) goto LAB_00430988;
                                    ppppppuStack_3bc = pppppppuVar41[1];
                                    pppppppuVar52 = pppppppuVar41 + 1;
                                  }
                                  else {
                                    iVar15 = (*(code *)PTR_strcmp_006a9b18)(ppppppuVar43,"-cert");
                                    if (iVar15 == 0) {
                                      iVar14 = iVar14 + -1;
                                      if (iVar14 == 0) goto LAB_00430988;
                                      ppppppuStack_40c = pppppppuVar41[1];
                                      pppppppuVar52 = pppppppuVar41 + 1;
                                    }
                                    else {
                                      iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                         (ppppppuVar43,"-selfsign");
                                      if (iVar15 == 0) {
                                        iStack_418 = 1;
                                      }
                                      else if (((cVar1 == '-') &&
                                               (*(char *)((int)ppppppuVar43 + 1) == 'i')) &&
                                              ((*(char *)((int)ppppppuVar43 + 2) == 'n' &&
                                               (*(char *)((int)ppppppuVar43 + 3) == '\0')))) {
                                        iVar14 = iVar14 + -1;
                                        if (iVar14 == 0) goto LAB_00430988;
                                        ppppppuStack_424 = pppppppuVar41[1];
                                        bVar3 = true;
                                        pppppppuVar52 = pppppppuVar41 + 1;
                                      }
                                      else {
                                        iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                           (ppppppuVar43,&DAT_00632514);
                                        if (iVar15 == 0) {
                                          iVar14 = iVar14 + -1;
                                          if (iVar14 == 0) goto LAB_00430988;
                                          ppppppuStack_408 = pppppppuVar41[1];
                                          pppppppuVar52 = pppppppuVar41 + 1;
                                        }
                                        else {
                                          iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                             (ppppppuVar43,"-outdir");
                                          if (iVar15 == 0) {
                                            iVar14 = iVar14 + -1;
                                            if (iVar14 == 0) goto LAB_00430988;
                                            ppppppuStack_44c = pppppppuVar41[1];
                                            pppppppuVar52 = pppppppuVar41 + 1;
                                          }
                                          else {
                                            iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                               (ppppppuVar43,"-sigopt");
                                            if (iVar15 == 0) {
                                              iVar14 = iVar14 + -1;
                                              if (iVar14 == 0) {
LAB_00430988:
                                                (*(code *)PTR_BIO_printf_006a6e38)
                                                          (*(undefined4 *)puVar10,
                                                           "unknown option %s\n",ppppppuVar43);
                                                if (ca_usage._0_4_ == 0) goto LAB_00430670;
                                                puVar44 = ca_usage;
                                                do {
                                                  puVar44 = (undefined1 *)((int)puVar44 + 4);
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar10,"%s");
                                                } while (*(int *)puVar44 != 0);
                                                iStack_470 = 0;
                                                goto LAB_00430674;
                                              }
                                              if ((iStack_468 == 0) &&
                                                 (iStack_468 = (*(code *)PTR_sk_new_null_006a6fa4)()
                                                 , iStack_468 == 0)) {
                                                ppppppuVar43 = *pppppppuVar41;
                                                goto LAB_00430988;
                                              }
                                              pppppppuVar52 = pppppppuVar41 + 1;
                                              iVar15 = (*(code *)PTR_sk_push_006a6fa8)
                                                                 (iStack_468,pppppppuVar41[1]);
                                              if (iVar15 == 0) {
                                                ppppppuVar43 = pppppppuVar41[1];
                                                goto LAB_00430988;
                                              }
                                            }
                                            else {
                                              iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                 (ppppppuVar43,"-notext");
                                              if (iVar15 == 0) {
                                                bVar8 = true;
                                              }
                                              else {
                                                iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                   (ppppppuVar43,"-batch");
                                                if (iVar15 == 0) {
                                                  iStack_434 = 1;
                                                }
                                                else {
                                                  iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (ppppppuVar43,"-preserveDN");
                                                  if (iVar15 == 0) {
                                                    preserve = 1;
                                                  }
                                                  else {
                                                    iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (ppppppuVar43,"-noemailDN");
                                                    if (iVar15 == 0) {
                                                      bVar4 = false;
                                                    }
                                                    else {
                                                      iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (ppppppuVar43,"-gencrl");
                                                      if (iVar15 == 0) {
                                                        bVar6 = true;
                                                      }
                                                      else {
                                                        iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (ppppppuVar43,
                                                                            "-msie_hack");
                                                        if (iVar15 == 0) {
                                                          msie_hack = 1;
                                                        }
                                                        else {
                                                          iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (ppppppuVar43,
                                                                              "-crldays");
                                                          if (iVar15 == 0) {
                                                            iVar14 = iVar14 + -1;
                                                            if (iVar14 == 0) goto LAB_00430988;
                                                            iStack_3b8 = (*(code *)
                                                  PTR_strtol_006a9958)(pppppppuVar41[1],0,10);
                                                  pppppppuVar52 = pppppppuVar41 + 1;
                                                  }
                                                  else {
                                                    iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (ppppppuVar43,"-crlhours");
                                                    if (iVar15 == 0) {
                                                      iVar14 = iVar14 + -1;
                                                      if (iVar14 == 0) goto LAB_00430988;
                                                      iStack_3b4 = (*(code *)PTR_strtol_006a9958)
                                                                             (pppppppuVar41[1],0,10)
                                                      ;
                                                      pppppppuVar52 = pppppppuVar41 + 1;
                                                    }
                                                    else {
                                                      iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (ppppppuVar43,"-crlsec");
                                                      if (iVar15 == 0) {
                                                        iVar14 = iVar14 + -1;
                                                        if (iVar14 == 0) goto LAB_00430988;
                                                        iStack_400 = (*(code *)PTR_strtol_006a9958)
                                                                               (pppppppuVar41[1],0,
                                                                                10);
                                                        pppppppuVar52 = pppppppuVar41 + 1;
                                                      }
                                                      else {
                                                        iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (ppppppuVar43,"-infiles")
                                                        ;
                                                        if (iVar15 == 0) {
                                                          iVar14 = iVar14 + -1;
                                                          pppppppuVar41 = pppppppuVar41 + 1;
                                                          bVar3 = true;
                                                          break;
                                                        }
                                                        iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (ppppppuVar43,"-ss_cert")
                                                        ;
                                                        if (iVar15 == 0) {
                                                          iVar14 = iVar14 + -1;
                                                          if (iVar14 == 0) goto LAB_00430988;
                                                          ppppppuStack_404 = pppppppuVar41[1];
                                                          bVar3 = true;
                                                          pppppppuVar52 = pppppppuVar41 + 1;
                                                        }
                                                        else {
                                                          iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (ppppppuVar43,"-spkac")
                                                          ;
                                                          if (iVar15 == 0) {
                                                            iVar14 = iVar14 + -1;
                                                            if (iVar14 == 0) goto LAB_00430988;
                                                            ppppppuStack_430 = pppppppuVar41[1];
                                                            bVar3 = true;
                                                            pppppppuVar52 = pppppppuVar41 + 1;
                                                          }
                                                          else {
                                                            iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (ppppppuVar43,
                                                                                "-revoke");
                                                            if (iVar15 == 0) {
                                                              iVar14 = iVar14 + -1;
                                                              if (iVar14 == 0) goto LAB_00430988;
                                                              ppppppuStack_424 = pppppppuVar41[1];
                                                              bVar9 = true;
                                                              pppppppuVar52 = pppppppuVar41 + 1;
                                                            }
                                                            else {
                                                              iVar15 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(ppppppuVar43,"-extensions")
                                                              ;
                                                              if (iVar15 == 0) {
                                                                iVar14 = iVar14 + -1;
                                                                if (iVar14 == 0) goto LAB_00430988;
                                                                ppppppuStack_45c = pppppppuVar41[1];
                                                                pppppppuVar52 = pppppppuVar41 + 1;
                                                              }
                                                              else {
                                                                iVar15 = (*(code *)
                                                  PTR_strcmp_006a9b18)(ppppppuVar43,"-extfile");
                                                  if (iVar15 == 0) {
                                                    iVar14 = iVar14 + -1;
                                                    if (iVar14 == 0) goto LAB_00430988;
                                                    ppppppuStack_428 = pppppppuVar41[1];
                                                    pppppppuVar52 = pppppppuVar41 + 1;
                                                  }
                                                  else {
                                                    iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (ppppppuVar43,"-status");
                                                    if (iVar15 == 0) {
                                                      iVar14 = iVar14 + -1;
                                                      if (iVar14 == 0) goto LAB_00430988;
                                                      ppppppuStack_42c = pppppppuVar41[1];
                                                      pppppppuVar52 = pppppppuVar41 + 1;
                                                    }
                                                    else {
                                                      iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (ppppppuVar43,"-updatedb");
                                                      if (iVar15 == 0) {
                                                        bVar7 = true;
                                                      }
                                                      else {
                                                        iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (ppppppuVar43,"-crlexts")
                                                        ;
                                                        if (iVar15 == 0) {
                                                          iVar14 = iVar14 + -1;
                                                          if (iVar14 == 0) goto LAB_00430988;
                                                          ppppppuStack_438 = pppppppuVar41[1];
                                                          pppppppuVar52 = pppppppuVar41 + 1;
                                                        }
                                                        else {
                                                          iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (ppppppuVar43,
                                                                              "-crl_reason");
                                                          if (iVar15 == 0) {
                                                            iVar14 = iVar14 + -1;
                                                            if (iVar14 == 0) goto LAB_00430988;
                                                            ppppppuStack_41c = pppppppuVar41[1];
                                                            uStack_420 = 1;
                                                            pppppppuVar52 = pppppppuVar41 + 1;
                                                          }
                                                          else {
                                                            iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (ppppppuVar43,
                                                                                "-crl_hold");
                                                            if (iVar15 == 0) {
                                                              iVar14 = iVar14 + -1;
                                                              if (iVar14 == 0) goto LAB_00430988;
                                                              ppppppuStack_41c = pppppppuVar41[1];
                                                              uStack_420 = 2;
                                                              pppppppuVar52 = pppppppuVar41 + 1;
                                                            }
                                                            else {
                                                              iVar15 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(ppppppuVar43,
                                                                         "-crl_compromise");
                                                              if (iVar15 == 0) {
                                                                iVar14 = iVar14 + -1;
                                                                if (iVar14 == 0) goto LAB_00430988;
                                                                ppppppuStack_41c = pppppppuVar41[1];
                                                                uStack_420 = 3;
                                                                pppppppuVar52 = pppppppuVar41 + 1;
                                                              }
                                                              else {
                                                                iVar15 = (*(code *)
                                                  PTR_strcmp_006a9b18)
                                                            (ppppppuVar43,"-crl_CA_compromise");
                                                  if (iVar15 == 0) {
                                                    iVar14 = iVar14 + -1;
                                                    if (iVar14 == 0) goto LAB_00430988;
                                                    ppppppuStack_41c = pppppppuVar41[1];
                                                    uStack_420 = 4;
                                                    pppppppuVar52 = pppppppuVar41 + 1;
                                                  }
                                                  else {
                                                    iVar15 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (ppppppuVar43,"-engine");
                                                    if ((iVar15 != 0) ||
                                                       (iVar14 = iVar14 + -1, iVar14 == 0))
                                                    goto LAB_00430988;
                                                    ppppppuStack_480 = pppppppuVar41[1];
                                                    pppppppuVar52 = pppppppuVar41 + 1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      iVar14 = iVar14 + -1;
      pppppppuVar41 = pppppppuVar52 + 1;
    } while (iVar14 != 0);
  }
LAB_004305cc:
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  if (((ppppppuVar51 == (undefined4 ******)0x0) &&
      (ppppppuVar51 = (undefined4 ******)(*(code *)PTR_getenv_006a9a60)("OPENSSL_CONF"),
      ppppppuVar51 == (undefined4 ******)0x0)) &&
     (ppppppuVar51 = (undefined4 ******)(*(code *)PTR_getenv_006a9a60)("SSLEAY_CONF"),
     ppppppuVar51 == (undefined4 ******)0x0)) {
    uVar16 = (*(code *)PTR_X509_get_default_cert_area_006a7064)();
    iVar15 = (*(code *)PTR_strlen_006a9a24)(uVar16);
    iVar15 = iVar15 + 0xd;
    ppppppuVar43 = (undefined4 ******)
                   (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar15,&DAT_0063526c,0x232);
    if (ppppppuVar43 == (undefined4 ******)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"Out of memory\n");
      iStack_470 = 0;
      goto LAB_00430680;
    }
    (*(code *)PTR_BUF_strlcpy_006a6f64)(ppppppuVar43,uVar16,iVar15);
    (*(code *)PTR_BUF_strlcat_006a6f68)(ppppppuVar43,&DAT_0063b2b4,iVar15);
    (*(code *)PTR_BUF_strlcat_006a6f68)(ppppppuVar43,"openssl.cnf",iVar15);
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar10,"Using configuration from %s\n",ppppppuVar43);
    conf = (*(code *)PTR_NCONF_new_006a6e58)(0);
    iVar15 = (*(code *)PTR_NCONF_load_006a6e5c)(conf,ppppppuVar43,&iStack_3b0);
    ppppppuVar51 = ppppppuVar43;
    if (iVar15 < 1) goto LAB_00430638;
    (*(code *)PTR_CRYPTO_free_006a6e88)(ppppppuVar43);
  }
  else {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar10,"Using configuration from %s\n",ppppppuVar51);
    conf = (*(code *)PTR_NCONF_new_006a6e58)(0);
    iVar15 = (*(code *)PTR_NCONF_load_006a6e5c)(conf,ppppppuVar51,&iStack_3b0);
    if (iVar15 < 1) {
      ppppppuVar43 = (undefined4 ******)0x0;
      goto LAB_00430638;
    }
  }
  puVar29 = PTR_bio_err_006a6e3c;
  iVar15 = (*(code *)PTR_load_config_006a6e64)(*(undefined4 *)puVar10,conf);
  if (iVar15 == 0) goto LAB_00430670;
  uVar16 = (*(code *)PTR_setup_engine_006a6ec4)(*(undefined4 *)puVar29,ppppppuStack_480,0);
  if ((section == (undefined4 ******)0x0) &&
     (section = (undefined4 ******)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,"ca","default_ca"),
     section == (undefined4 ******)0x0)) {
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar29,"variable lookup failed for %s::%s\n","ca","default_ca");
    goto LAB_00430670;
  }
  if (conf != 0) {
    iVar15 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,0,"oid_file");
    if ((iVar15 == 0) || (iVar15 = (*(code *)PTR_BIO_new_file_006a6eac)(iVar15,"r"), iVar15 == 0)) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else {
      (*(code *)PTR_OBJ_create_objects_006a6eb0)(iVar15);
      (*(code *)PTR_BIO_free_006a6e70)(iVar15);
    }
    iVar15 = (*(code *)PTR_add_oid_section_006a6e60)(*(undefined4 *)puVar10,conf);
    if (iVar15 == 0) {
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
      goto LAB_00430670;
    }
  }
  iStack_470 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,"ca","RANDFILE");
  if (iStack_470 == 0) {
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
  }
  (*(code *)PTR_app_RAND_load_file_006a6ecc)(iStack_470,*(undefined4 *)puVar10,0);
  iVar15 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"string_mask");
  if (iVar15 == 0) {
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
  }
  else {
    iVar17 = (*(code *)PTR_ASN1_STRING_set_default_mask_asc_006a6ec0)(iVar15);
    if (iVar17 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"Invalid global string mask setting %s\n",
                 iVar15);
      goto LAB_00430674;
    }
  }
  if (iStack_46c == 0x1000) {
LAB_00430ce4:
    iStack_46c = 0x1000;
  }
  else {
    pcVar18 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,&DAT_00633198);
    if (pcVar18 == (char *)0x0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else if ((((*pcVar18 == 'y') && (pcVar18[1] == 'e')) && (pcVar18[2] == 's')) &&
            (pcVar18[3] == '\0')) goto LAB_00430ce4;
  }
  uStack_394 = 1;
  iVar15 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"unique_subject");
  if (iVar15 == 0) {
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
  }
  else {
    uStack_394 = (*(code *)PTR_parse_yesno_006a7068)(iVar15,1);
  }
  uVar19 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iStack_474 = (*(code *)PTR_BIO_new_006a6ea4)(uVar19);
  uVar19 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iStack_478 = (*(code *)PTR_BIO_new_006a6ea4)(uVar19);
  uVar19 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  ppppppuStack_480 = (undefined4 ******)(*(code *)PTR_BIO_new_006a6ea4)(uVar19);
  uVar19 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iStack_47c = (*(code *)PTR_BIO_new_006a6ea4)(uVar19);
  if (((iStack_474 == 0) || (iStack_478 == 0)) ||
     ((ppppppuStack_480 == (undefined4 ******)0x0 || (iStack_47c == 0)))) {
    ppppppuVar43 = (undefined4 ******)0x0;
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
    goto LAB_00430690;
  }
  if (ppppppuStack_42c != (undefined4 ******)0x0) {
    iVar14 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"database");
    if (iVar14 != 0) {
      ppppppuVar43 = (undefined4 ******)(*(code *)PTR_load_index_006a706c)(iVar14,&uStack_394);
      if (ppppppuVar43 == (undefined4 ******)0x0) goto LAB_00430690;
      iVar14 = (*(code *)PTR_index_index_006a7070)(ppppppuVar43);
      if (iVar14 == 0) goto LAB_00430690;
      puVar45 = auStack_374;
      auStack_374[0] = 0;
      auStack_374[1] = 0;
      auStack_374[2] = 0;
      pcStack_368 = (char *)0x0;
      uStack_364 = 0;
      uStack_360 = 0;
      iVar14 = (*(code *)PTR_strlen_006a9a24)(ppppppuStack_42c);
      pcVar18 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar14 + 2,&DAT_0063526c,0x98f);
      pcStack_368 = pcVar18;
      if (pcVar18 == (char *)0x0) {
        iVar14 = -1;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"Malloc failure\n");
      }
      else {
        uVar20 = (*(code *)PTR_strlen_006a9a24)(ppppppuStack_42c);
        puVar29 = PTR_strlen_006a9a24;
        if ((uVar20 & 1) == 0) {
          (*(code *)PTR_memcpy_006a9aec)(pcVar18,ppppppuStack_42c,uVar20);
          iVar14 = (*(code *)PTR_strlen_006a9a24)(ppppppuStack_42c);
          pcStack_368[iVar14] = '\0';
        }
        else {
          *pcVar18 = '0';
          uVar16 = (*(code *)puVar29)(ppppppuStack_42c);
          (*(code *)PTR_memcpy_006a9aec)(pcStack_368 + 1,ppppppuStack_42c,uVar16);
          iVar14 = (*(code *)PTR_strlen_006a9a24)(ppppppuStack_42c);
          pcStack_368[iVar14 + 1] = '\0';
        }
        pcVar18 = pcStack_368;
        uVar20 = (uint)*pcStack_368;
        if (uVar20 != 0) {
          piVar21 = (int *)(*(code *)PTR___ctype_toupper_loc_006a9b28)();
          iVar14 = 0;
          do {
            iVar14 = iVar14 + 1;
            *pcVar18 = (char)*(undefined4 *)(*piVar21 + (uVar20 & 0xff) * 4);
            pcVar18 = pcStack_368 + iVar14;
            uVar20 = (uint)*pcVar18;
          } while (uVar20 != 0);
        }
        ppcVar22 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a7020)(ppppppuVar43[1],3,puVar45);
        if (ppcVar22 == (char **)0x0) {
          iVar14 = -1;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar10,"Serial %s not present in db.\n",pcStack_368);
        }
        else {
          cVar1 = **ppcVar22;
          if (cVar1 == 'V') {
            iVar14 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"%s=Valid (%c)\n",pcStack_368,0x56);
          }
          else if (cVar1 == 'R') {
            iVar14 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"%s=Revoked (%c)\n",pcStack_368,0x52);
          }
          else if (cVar1 == 'E') {
            iVar14 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"%s=Expired (%c)\n",pcStack_368,0x45);
          }
          else if (cVar1 == 'S') {
            iVar14 = 1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"%s=Suspended (%c)\n",pcStack_368,0x53);
          }
          else {
            iVar14 = -1;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar10,"%s=Unknown (%c).\n",pcStack_368);
          }
        }
      }
      do {
        if (*puVar45 != 0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        puVar45 = puVar45 + 1;
      } while (puVar45 != auStack_35c);
      if (iVar14 == 1) goto LAB_00430690;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar10,"Error verifying serial %s!\n",ppppppuStack_42c);
      goto LAB_00430690;
    }
    pcVar18 = "database";
LAB_004316ec:
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,pcVar18);
    ppppppuVar43 = (undefined4 ******)0x0;
    goto LAB_00430690;
  }
  if ((ppppppuStack_410 == (undefined4 ******)0x0) &&
     (ppppppuStack_410 =
           (undefined4 ******)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"private_key"),
     ppppppuStack_410 == (undefined4 ******)0x0)) {
    pcVar18 = "private_key";
    goto LAB_004316ec;
  }
  if (ppppppuStack_3bc == (undefined4 ******)0x0) {
    iVar15 = (*(code *)PTR_app_passwd_006a6e54)
                       (*(undefined4 *)puVar10,ppppppuStack_3fc,0,&ppppppuStack_3bc,0);
    if (iVar15 == 0) {
      iVar17 = 0;
      iVar24 = 0;
      ppppppuVar43 = (undefined4 ******)0x0;
      iVar15 = 0;
      iVar14 = 0;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"Error getting password\n");
      iVar48 = 1;
      iStack_48c = 0;
      bVar5 = true;
      goto LAB_004306ac;
    }
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  iStack_48c = (*(code *)PTR_load_key_006a6ec8)
                         (*(undefined4 *)puVar10,ppppppuStack_410,uStack_3f0,0,ppppppuStack_3bc,
                          uVar16,"CA private key");
  ppppppuVar51 = ppppppuStack_3bc;
  if (ppppppuStack_3bc != (undefined4 ******)0x0) {
    uVar19 = (*(code *)PTR_strlen_006a9a24)(ppppppuStack_3bc);
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(ppppppuVar51,uVar19);
  }
  if (iStack_48c == 0) {
LAB_004318d8:
    iVar17 = 0;
    iVar24 = 0;
    ppppppuVar43 = (undefined4 ******)0x0;
    iVar15 = 0;
    iVar14 = 0;
    iVar48 = 1;
    goto LAB_004306ac;
  }
  if ((((iStack_418 == 0) || (ppppppuStack_430 != (undefined4 ******)0x0)) ||
      (ppppppuStack_404 != (undefined4 ******)0x0)) || (bVar6)) {
    if ((ppppppuStack_40c == (undefined4 ******)0x0) &&
       (ppppppuStack_40c =
             (undefined4 ******)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"certificate")
       , ppppppuStack_40c == (undefined4 ******)0x0)) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,"certificate")
      ;
      goto LAB_004318d8;
    }
    iVar15 = (*(code *)PTR_load_cert_006a7078)
                       (*(undefined4 *)puVar10,ppppppuStack_40c,3,0,uVar16,"CA certificate");
    if (iVar15 != 0) {
      iVar17 = (*(code *)PTR_X509_check_private_key_006a707c)(iVar15,iStack_48c);
      if (iVar17 != 0) {
        ppppppuStack_3fc = (undefined4 ******)iVar15;
        if (iStack_418 != 0) goto LAB_004316d4;
        goto LAB_004313f4;
      }
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,
                 "CA certificate and CA private key do not match\n");
    }
  }
  else {
    iVar15 = 0;
LAB_004316d4:
    ppppppuStack_3fc = (undefined4 ******)0x0;
LAB_004313f4:
    pbVar23 = (byte *)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,"ca","preserve");
    if (pbVar23 == (byte *)0x0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else if ((*pbVar23 & 0xdf) == 0x59) {
      preserve = 1;
    }
    pbVar23 = (byte *)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,"ca","msie_hack");
    if (pbVar23 == (byte *)0x0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else if ((*pbVar23 & 0xdf) == 0x59) {
      msie_hack = 1;
    }
    iVar17 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"name_opt");
    if (iVar17 == 0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      ppppppuStack_410 = (undefined4 ******)0x1;
    }
    else {
      iVar24 = (*(code *)PTR_set_name_ex_006a6fac)(&uStack_3a4,iVar17);
      if (iVar24 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar10,"Invalid name options: \"%s\"\n",iVar17);
        goto LAB_0043181c;
      }
      ppppppuStack_410 = (undefined4 ******)0x0;
    }
    iVar17 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"cert_opt");
    if (iVar17 == 0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else {
      iVar24 = (*(code *)PTR_set_cert_ex_006a6fb0)(&uStack_3a0,iVar17);
      if (iVar24 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar10,"Invalid certificate options: \"%s\"\n",iVar17);
        goto LAB_0043181c;
      }
      ppppppuStack_410 = (undefined4 ******)0x0;
    }
    iVar17 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"copy_extensions");
    if (iVar17 == 0) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
    }
    else {
      iVar24 = (*(code *)PTR_set_ext_copy_006a7080)(&uStack_39c,iVar17);
      if (iVar24 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar10,"Invalid extension copy option: \"%s\"\n",iVar17);
        goto LAB_0043181c;
      }
    }
    if ((ppppppuStack_44c == (undefined4 ******)0x0) && (bVar3)) {
      ppppppuStack_44c =
           (undefined4 ******)(*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"new_certs_dir")
      ;
      if (ppppppuStack_44c == (undefined4 ******)0x0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar10,
                   "there needs to be defined a directory for new certificate to be placed in\n");
      }
      else {
        iVar17 = (*(code *)PTR_access_006a99cc)(ppppppuStack_44c,7);
        if (iVar17 == 0) {
          iVar17 = (*(code *)PTR_app_isdir_006a7088)(ppppppuStack_44c);
          if (0 < iVar17) goto LAB_00431550;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar10,"%s need to be a directory\n",ppppppuStack_44c);
          (*(code *)PTR_perror_006a9a80)(ppppppuStack_44c);
        }
        else {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar10,"I am unable to access the %s directory\n",
                     ppppppuStack_44c);
          (*(code *)PTR_perror_006a9a80)(ppppppuStack_44c);
        }
      }
    }
    else {
LAB_00431550:
      iVar25 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"database");
      if (iVar25 != 0) {
        ppppppuVar43 = (undefined4 ******)(*(code *)PTR_load_index_006a706c)(iVar25,&uStack_394);
        if (ppppppuVar43 != (undefined4 ******)0x0) {
          for (iVar17 = 0; iVar24 = (*(code *)PTR_sk_num_006a6e2c)(ppppppuVar43[1][1]),
              iVar17 < iVar24; iVar17 = iVar17 + 1) {
            ppcVar22 = (char **)(*(code *)PTR_sk_value_006a6e24)(ppppppuVar43[1][1],iVar17);
            if (**ppcVar22 == 'R') {
              iVar24 = make_revoked(0,ppcVar22[2]);
              if (iVar24 == 0) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10," in entry %d\n",iVar17 + 1);
                goto LAB_00431690;
              }
            }
            else if (*ppcVar22[2] != '\0') {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar10,
                         "entry %d: not revoked yet, but has a revocation date\n",iVar17 + 1);
              goto LAB_00431690;
            }
            iVar24 = (*(code *)PTR_ASN1_TIME_set_string_006a7084)(0,ppcVar22[1]);
            if (iVar24 == 0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar10,"entry %d: invalid expiry date\n",iVar17 + 1);
              goto LAB_00431690;
            }
            pcVar47 = ppcVar22[3];
            uVar20 = (*(code *)PTR_strlen_006a9a24)(pcVar47);
            pcVar18 = pcVar47;
            if (*pcVar47 == '-') {
              uVar20 = uVar20 - 1;
              pcVar18 = pcVar47 + 1;
            }
            if (((uVar20 & 1) != 0) || ((int)uVar20 < 2)) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar10,"entry %d: bad serial number length (%d)\n",
                         iVar17 + 1,uVar20);
              goto LAB_00431690;
            }
            while( true ) {
              uVar20 = (uint)*pcVar18;
              if (uVar20 == 0) break;
              if ((9 < (uVar20 & 0xff) - 0x30) && (5 < (uVar20 & 0xdf) - 0x41)) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10,
                           "entry %d: bad serial number characters, char pos %ld, char is \'%c\'\n",
                           iVar17 + 1,(int)pcVar18 - (int)pcVar47,uVar20);
                goto LAB_00431690;
              }
              pcVar18 = pcVar18 + 1;
            }
          }
          if (iVar48 != 0) {
            (*(code *)PTR_BIO_ctrl_006a6e18)
                      (iStack_478,0x6a,0x10,*(undefined4 *)PTR_stdout_006a99c8);
            (*(code *)PTR_TXT_DB_write_006a708c)(iStack_478,ppppppuVar43[1]);
            uVar46 = *(undefined4 *)puVar10;
            uVar19 = (*(code *)PTR_sk_num_006a6e2c)(ppppppuVar43[1][1]);
            (*(code *)PTR_BIO_printf_006a6e38)
                      (uVar46,"%d entries loaded from the database\n",uVar19);
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"generating index\n");
          }
          iVar17 = (*(code *)PTR_index_index_006a7070)(ppppppuVar43);
          if (iVar17 != 0) {
            if (!bVar7) {
LAB_00431ddc:
              if (ppppppuStack_428 != (undefined4 ******)0x0) {
                extconf = (*(code *)PTR_NCONF_new_006a6e58)(0);
                iVar17 = (*(code *)PTR_NCONF_load_006a6e5c)(extconf,ppppppuStack_428,&iStack_3b0);
                if (0 < iVar17) {
                  if (iVar48 != 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,"Successfully loaded extensions file %s\n",
                               ppppppuStack_428);
                  }
                  if (ppppppuStack_45c == (undefined4 ******)0x0) {
                    ppppppuVar51 = (undefined4 ******)
                                   (*(code *)PTR_NCONF_get_string_006a6ea8)
                                             (extconf,"default","extensions");
                    ppppppuStack_45c = (undefined4 ******)0x66f134;
                    if (ppppppuVar51 != (undefined4 ******)0x0) {
                      ppppppuStack_45c = ppppppuVar51;
                    }
                  }
                  goto LAB_00431e7c;
                }
                uVar16 = *(undefined4 *)puVar10;
                if (0 < iStack_3b0) {
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (uVar16,"ERROR: on line %ld of config file \'%s\'\n",iStack_3b0,
                             ppppppuStack_428);
                  goto LAB_00432228;
                }
                pcVar18 = "ERROR: loading the config file \'%s\'\n";
                ppppppuStack_448 = ppppppuStack_428;
LAB_00432ea0:
                (*(code *)PTR_BIO_printf_006a6e38)(uVar16,pcVar18,ppppppuStack_448);
                goto LAB_00432228;
              }
LAB_00431e7c:
              if ((bVar3) || (bVar6)) {
                if (ppppppuStack_408 == (undefined4 ******)0x0) {
                  (*(code *)PTR_BIO_ctrl_006a6e18)
                            (ppppppuStack_480,0x6a,0x10,*(undefined4 *)PTR_stdout_006a99c8);
                }
                else {
                  iVar17 = (*(code *)PTR_BIO_ctrl_006a6e18)
                                     (ppppppuStack_480,0x6c,5,ppppppuStack_408);
                  if (iVar17 < 1) {
                    (*(code *)PTR_perror_006a9a80)(ppppppuStack_408);
                    goto LAB_00432228;
                  }
                }
              }
              if ((ppppppuStack_43c == (undefined4 ******)0x0) &&
                 (ppppppuStack_43c =
                       (undefined4 ******)
                       (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"default_md"),
                 ppppppuStack_43c == (undefined4 ******)0x0)) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,
                           "default_md");
                goto LAB_00432228;
              }
              iVar17 = (*(code *)PTR_strcmp_006a9b18)(ppppppuStack_43c,"default");
              if (iVar17 == 0) {
                iVar17 = (*(code *)PTR_EVP_PKEY_get_default_digest_nid_006a7098)
                                   (iStack_48c,auStack_390);
                if (iVar17 < 1) {
                  (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar10,"no default digest\n");
                  goto LAB_00432228;
                }
                ppppppuStack_43c =
                     (undefined4 ******)(*(code *)PTR_OBJ_nid2sn_006a709c)(auStack_390[0]);
              }
              puVar27 = (undefined4 *)(*(code *)PTR_EVP_get_digestbyname_006a6f2c)(ppppppuStack_43c)
              ;
              if (puVar27 == (undefined4 *)0x0) {
                uVar16 = *(undefined4 *)puVar10;
                pcVar18 = "%s is an unsupported message digest type\n";
                ppppppuStack_448 = ppppppuStack_43c;
                goto LAB_00432ea0;
              }
              iVar17 = 0;
              if (!bVar3) goto LAB_00433214;
              if ((bVar4 != false) &&
                 (pbVar23 = (byte *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                              (conf,section,"email_in_dn"), pbVar23 != (byte *)0x0))
              {
                iVar17 = 0x6e - (uint)*pbVar23;
                if ((iVar17 == 0) && (iVar17 = 0x6f - (uint)pbVar23[1], iVar17 == 0)) {
                  iVar17 = -(uint)pbVar23[2];
                }
                bVar4 = iVar17 != 0;
              }
              if (iVar48 == 0) {
                if ((ppppppuStack_448 == (undefined4 ******)0x0) &&
                   (ppppppuStack_448 =
                         (undefined4 ******)
                         (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"policy"),
                   ppppppuStack_448 == (undefined4 ******)0x0)) {
LAB_00433acc:
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,
                             "policy");
                  goto LAB_00432228;
                }
              }
              else {
                uVar46 = *(undefined4 *)puVar10;
                uVar19 = (*(code *)PTR_OBJ_nid2ln_006a711c)(*puVar27);
                (*(code *)PTR_BIO_printf_006a6e38)(uVar46,"message digest is %s\n",uVar19);
                if ((ppppppuStack_448 == (undefined4 ******)0x0) &&
                   (ppppppuStack_448 =
                         (undefined4 ******)
                         (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"policy"),
                   ppppppuStack_448 == (undefined4 ******)0x0)) goto LAB_00433acc;
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10,"policy is %s\n",ppppppuStack_448);
              }
              iVar26 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"serial");
              if (iVar26 == 0) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,
                           "serial");
              }
              else {
                if (extconf == 0) {
                  if ((ppppppuStack_45c == (undefined4 ******)0x0) &&
                     (ppppppuStack_45c =
                           (undefined4 ******)
                           (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"x509_extensions"),
                     ppppppuStack_45c == (undefined4 ******)0x0)) {
                    (*(code *)PTR_ERR_clear_error_006a6ee0)();
                  }
                  else {
                    (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_390,0,0,0,0,1);
                    (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_390,conf);
                    iVar17 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                       (conf,auStack_390,ppppppuStack_45c,0);
                    if (iVar17 == 0) {
                      uVar16 = *(undefined4 *)puVar10;
                      pcVar18 = "Error Loading extension section %s\n";
                      ppppppuStack_448 = ppppppuStack_45c;
                      goto LAB_00432ea0;
                    }
                  }
                }
                if (((undefined4 ******)pcStack_454 == (undefined4 ******)0x0) &&
                   (pcStack_454 = (char *)(*(code *)PTR_NCONF_get_string_006a6ea8)
                                                    (conf,section,"default_startdate"),
                   (undefined4 ******)pcStack_454 == (undefined4 ******)0x0)) {
                  (*(code *)PTR_ERR_clear_error_006a6ee0)();
                  pcStack_454 = "today";
                }
                else {
                  iVar17 = (*(code *)PTR_ASN1_TIME_set_string_006a7084)(0,pcStack_454);
                  if (iVar17 == 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,
                               "start date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n"
                              );
                    goto LAB_00432228;
                  }
                }
                if ((ppppppuStack_450 == (undefined4 ******)0x0) &&
                   (ppppppuStack_450 =
                         (undefined4 ******)
                         (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"default_enddate"),
                   ppppppuStack_450 == (undefined4 ******)0x0)) {
                  (*(code *)PTR_ERR_clear_error_006a6ee0)();
                }
                else {
                  iVar17 = (*(code *)PTR_ASN1_TIME_set_string_006a7084)(0,ppppppuStack_450);
                  if (iVar17 == 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,
                               "end date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n"
                              );
                    goto LAB_00432228;
                  }
                }
                if (ppppppuStack_3a8 == (undefined4 ******)0x0) {
                  iVar17 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                     (conf,section,"default_days",&ppppppuStack_3a8);
                  if (iVar17 == 0) {
                    ppppppuStack_3a8 = (undefined4 ******)0x0;
                    ppppppuVar51 = ppppppuStack_450;
                  }
                  else {
                    ppppppuVar51 = ppppppuStack_3a8;
                    if (ppppppuStack_450 != (undefined4 ******)0x0) goto LAB_00431fe8;
                  }
                  if (ppppppuVar51 == (undefined4 ******)0x0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,"cannot lookup how many days to certify for\n"
                              );
                    goto LAB_00432228;
                  }
                }
LAB_00431fe8:
                iStack_3ac = (*(code *)PTR_load_serial_006a70a0)(iVar26,iStack_460,0);
                if (iStack_3ac != 0) {
                  if (iVar48 != 0) {
                    if (*(int *)(iStack_3ac + 4) == 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"next serial number is 00\n");
                    }
                    else {
                      iVar17 = (*(code *)PTR_BN_bn2hex_006a7018)(iStack_3ac);
                      if (iVar17 == 0) goto LAB_00432228;
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"next serial number is %s\n",iVar17);
                      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar17);
                    }
                  }
                  iVar28 = (*(code *)PTR_NCONF_get_section_006a6ed4)(conf,ppppppuStack_448);
                  if (iVar28 == 0) {
                    uVar16 = *(undefined4 *)puVar10;
                    pcVar18 = "unable to find \'section\' for %s\n";
                    goto LAB_00432ea0;
                  }
                  iVar17 = (*(code *)PTR_sk_new_null_006a6fa4)();
                  uVar12 = uStack_39c;
                  uVar46 = uStack_3a0;
                  uVar19 = uStack_3a4;
                  ppppppuVar51 = ppppppuStack_3a8;
                  iVar37 = iStack_3ac;
                  iVar24 = conf;
                  if (iVar17 == 0) {
                    uVar16 = *(undefined4 *)puVar10;
                    pcVar18 = "Memory allocation failure\n";
LAB_00432b74:
                    iVar24 = 0;
                    (*(code *)PTR_BIO_printf_006a6e38)(uVar16,pcVar18);
                    iVar14 = 0;
                    iVar48 = 1;
                    goto LAB_004306ac;
                  }
                  if (ppppppuStack_430 == (undefined4 ******)0x0) {
                    bVar3 = false;
                    iVar24 = 0;
                    iStack_3f4 = 2;
                    ppppppuStack_430 = (undefined4 ******)0x2;
                    ppppppuStack_448 = (undefined4 ******)0x1;
                    iStack_460 = 1;
                    iVar37 = 0;
                    goto LAB_00432538;
                  }
                  puVar29 = (undefined *)
                            (*(code *)PTR_CONF_load_006a70a4)(0,ppppppuStack_430,auStack_390);
                  if (puVar29 == (undefined *)0x0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,"error on line %ld of %s\n",auStack_390[0],
                               ppppppuStack_430);
                    puVar29 = *(undefined **)puVar10;
                    pcVar53 = (code *)PTR_ERR_print_errors_006a6e40;
LAB_00432e40:
                    iVar24 = 0;
                    (*pcVar53)(puVar29);
LAB_00432478:
                    iVar14 = 0;
                  }
                  else {
                    uVar30 = (*(code *)PTR_CONF_get_section_006a70a8)(puVar29,"default");
                    iVar31 = (*(code *)PTR_sk_num_006a6e2c)(uVar30);
                    if (iVar31 == 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"no name/value pairs found in %s\n",
                                 ppppppuStack_430);
                      (*(code *)PTR_CONF_free_006a70b4)(puVar29);
                      pcVar53 = (code *)PTR_CONF_free_006a70b4;
                      goto LAB_00432e40;
                    }
                    piVar21 = (int *)(*(code *)PTR_X509_REQ_new_006a6ed0)();
                    if (piVar21 == (int *)0x0) {
                      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
                      pcVar53 = (code *)PTR_CONF_free_006a70b4;
                      goto LAB_00432e40;
                    }
                    iVar31 = 0;
                    ppppppuStack_448 = (undefined4 ******)0x0;
                    uVar32 = *(undefined4 *)(*piVar21 + 0x10);
                    for (; iVar33 = (*(code *)PTR_sk_num_006a6e2c)(uVar30),
                        puVar50 = PTR_bio_err_006a6e3c, (int)ppppppuStack_448 < iVar33;
                        ppppppuStack_448 = (undefined4 ******)((int)ppppppuStack_448 + 1)) {
                      iVar33 = (*(code *)PTR_sk_value_006a6e24)(uVar30,ppppppuStack_448);
                      pbVar38 = *(byte **)(iVar33 + 4);
                      bVar2 = *pbVar38;
                      pbVar23 = pbVar38;
                      while (bVar2 != 0) {
                        if ((bVar2 == 0x3a) || ((bVar2 & 0xfd) == 0x2c)) {
                          if (*(byte *)((int)pbVar23 + 1) != 0) {
                            pbVar38 = (byte *)((int)pbVar23 + 1);
                          }
                          break;
                        }
                        pbVar23 = (byte *)((int)pbVar23 + 1);
                        bVar2 = *pbVar23;
                      }
                      uVar42 = *(undefined4 *)(iVar33 + 8);
                      iVar34 = (*(code *)PTR_OBJ_txt2nid_006a6f5c)(pbVar38);
                      if (iVar34 == 0) {
                        iVar34 = (*(code *)PTR_strcmp_006a9b18)(pbVar38,"SPKAC");
                        if ((iVar34 == 0) &&
                           (iVar31 = (*(code *)PTR_NETSCAPE_SPKI_b64_decode_006a70d4)
                                               (*(undefined4 *)(iVar33 + 8),0xffffffff), iVar31 == 0
                           )) {
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar10,
                                     "unable to load Netscape SPKAC structure\n");
                          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
                          iVar37 = -1;
                          goto LAB_004323f4;
                        }
                      }
                      else {
                        iVar33 = (*(code *)PTR_X509_NAME_add_entry_by_NID_006a6f78)
                                           (uVar32,iVar34,iStack_46c,uVar42,0xffffffff,0xffffffff,0)
                        ;
                        if (iVar33 == 0) {
                          iVar37 = -1;
                          goto LAB_004323f4;
                        }
                      }
                    }
                    if (iVar31 == 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"Netscape SPKAC structure not found in %s\n"
                                 ,ppppppuStack_430);
                      iVar37 = -1;
                    }
                    else {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,
                                 "Check that the SPKAC request matches the signature\n");
                      iVar33 = (*(code *)PTR_NETSCAPE_SPKI_get_pubkey_006a70ac)(iVar31);
                      if (iVar33 == 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar50,"error unpacking SPKAC public key\n");
                        iVar37 = -1;
                      }
                      else {
                        iVar34 = (*(code *)PTR_NETSCAPE_SPKI_verify_006a70b0)(iVar31,iVar33);
                        if (iVar34 < 1) {
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar50,
                                     "signature verification failed on SPKAC public key\n");
                          iVar37 = -1;
                        }
                        else {
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar50,"Signature ok\n");
                          (*(code *)PTR_X509_REQ_set_pubkey_006a6f30)(piVar21,iVar33);
                          (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar33);
                          iVar37 = do_body(&piStack_398,iStack_48c,iVar15,puVar27,iStack_468,iVar28,
                                           ppppppuVar43,iVar37,ppppppuStack_488,iStack_46c,
                                           uStack_458,bVar4,pcStack_454,ppppppuStack_450,
                                           ppppppuVar51,1,iVar48,piVar21,ppppppuStack_45c,iVar24,
                                           uVar46,uVar19,ppppppuStack_410,uVar12,0);
                        }
                      }
                    }
LAB_004323f4:
                    (*(code *)PTR_X509_REQ_free_006a6e8c)(piVar21);
                    (*(code *)PTR_CONF_free_006a70b4)(puVar29);
                    if (iVar31 != 0) {
                      (*(code *)PTR_NETSCAPE_SPKI_free_006a70b8)(iVar31);
                    }
                    iVar24 = 0;
                    if (iVar37 < 0) goto LAB_00432478;
                    if (iVar37 != 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"\n");
                      iVar24 = (*(code *)PTR_BN_add_word_006a70bc)(iStack_3ac,1);
                      if (iVar24 == 0) goto LAB_00432474;
                      iVar24 = (*(code *)PTR_sk_push_006a6fa8)(iVar17,piStack_398);
                      if (iVar24 != 0) {
                        iVar24 = 1;
                        iStack_3f4 = 3;
                        ppppppuStack_430 = (undefined4 ******)0x3;
                        if (ppppppuStack_408 != (undefined4 ******)0x0) {
                          iStack_434 = 1;
                        }
                        ppppppuStack_448 = (undefined4 ******)0x2;
                        iStack_460 = 2;
                        bVar3 = ppppppuStack_408 != (undefined4 ******)0x0;
                        iVar37 = 1;
                        goto LAB_00432538;
                      }
LAB_00432b60:
                      pcVar18 = "Memory allocation failure\n";
                      uVar16 = *(undefined4 *)PTR_bio_err_006a6e3c;
                      goto LAB_00432b74;
                    }
                    bVar3 = false;
                    iVar24 = 0;
                    iStack_3f4 = 2;
                    ppppppuStack_430 = (undefined4 ******)0x3;
                    ppppppuStack_448 = (undefined4 ******)0x1;
                    iStack_460 = 2;
                    iVar37 = 1;
LAB_00432538:
                    uVar12 = uStack_39c;
                    uVar46 = uStack_3a0;
                    uVar19 = uStack_3a4;
                    ppppppuVar51 = ppppppuStack_3a8;
                    iVar34 = iStack_3ac;
                    iVar33 = (int)ppppppuStack_448;
                    iVar31 = conf;
                    iVar35 = iStack_460;
                    if (ppppppuStack_404 == (undefined4 ******)0x0) goto LAB_004326d0;
                    iVar37 = (*(code *)PTR_load_cert_006a7078)
                                       (*(undefined4 *)puVar10,ppppppuStack_404,3,0,uVar16,
                                        ppppppuStack_404);
                    if (iVar37 == 0) {
LAB_00432474:
                      iVar24 = 0;
                      goto LAB_00432478;
                    }
                    if (iVar48 != 0) {
                      (*(code *)PTR_X509_print_006a70c0)(*(undefined4 *)PTR_bio_err_006a6e3c,iVar37)
                      ;
                    }
                    puVar29 = PTR_bio_err_006a6e3c;
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,
                               "Check that the request matches the signature\n");
                    iVar35 = (*(code *)PTR_X509_get_pubkey_006a6f08)(iVar37);
                    if (iVar35 == 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar29,"error unpacking public key\n");
                      iVar31 = -1;
                    }
                    else {
                      iVar36 = (*(code *)PTR_X509_verify_006a70c4)(iVar37,iVar35);
                      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar35);
                      if (iVar36 < 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar29,"Signature verification problems....\n");
                        iVar31 = 0;
                      }
                      else if (iVar36 == 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar29,
                                   "Signature did not match the certificate\n");
                        iVar31 = 0;
                      }
                      else {
                        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar29,"Signature ok\n");
                        uVar30 = (*(code *)PTR_EVP_md5_006a70c8)();
                        iVar35 = (*(code *)PTR_X509_to_X509_REQ_006a70cc)(iVar37,0,uVar30);
                        if (iVar35 == 0) {
                          iVar31 = -1;
                        }
                        else {
                          iVar31 = do_body(&piStack_398,iStack_48c,iVar15,puVar27,iStack_468,iVar28,
                                           ppppppuVar43,iVar34,ppppppuStack_488,iStack_46c,
                                           uStack_458,bVar4,pcStack_454,ppppppuStack_450,
                                           ppppppuVar51,iStack_434,iVar48,iVar35,ppppppuStack_45c,
                                           iVar31,uVar46,uVar19,ppppppuStack_410,uVar12,0);
                          (*(code *)PTR_X509_REQ_free_006a6e8c)(iVar35);
                        }
                      }
                    }
                    (*(code *)PTR_X509_free_006a6e90)(iVar37);
                    if (iVar31 < 0) goto LAB_00432474;
                    iVar35 = (int)ppppppuStack_430;
                    iVar37 = iStack_460;
                    if (iVar31 != 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"\n");
                      iVar24 = (*(code *)PTR_BN_add_word_006a70bc)(iStack_3ac,1);
                      if (iVar24 == 0) goto LAB_00432474;
                      iVar24 = (*(code *)PTR_sk_push_006a6fa8)(iVar17,piStack_398);
                      if (iVar24 == 0) goto LAB_00432b60;
                      ppppppuStack_448 = (undefined4 ******)iStack_3f4;
                      iVar24 = iVar33;
                    }
LAB_004326d0:
                    iStack_460 = iVar37;
                    iVar37 = iStack_460;
                    if (ppppppuStack_424 != (undefined4 ******)0x0) {
                      iVar31 = certify(&piStack_398,ppppppuStack_424,iStack_48c,ppppppuStack_3fc,
                                       puVar27,iStack_468,iVar28,ppppppuVar43,iStack_3ac,
                                       ppppppuStack_488,iStack_46c,uStack_458,bVar4,pcStack_454,
                                       ppppppuStack_450,ppppppuStack_3a8,iStack_434,ppppppuStack_45c
                                       ,conf,iVar48,uStack_3a0,uStack_3a4,ppppppuStack_410,
                                       uStack_39c,iStack_418);
                      if (iVar31 < 0) goto LAB_00432474;
                      iVar37 = iVar35;
                      if (iVar31 != 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"\n");
                        iVar24 = (*(code *)PTR_BN_add_word_006a70bc)(iStack_3ac,1);
                        if (iVar24 == 0) goto LAB_00432474;
                        iVar31 = (*(code *)PTR_sk_push_006a6fa8)(iVar17,piStack_398);
                        iVar24 = (int)ppppppuStack_448;
                        if (iVar31 == 0) goto LAB_00432b60;
                      }
                    }
                    iVar31 = iVar37 + iVar14;
                    iStack_460 = iVar37;
                    if (0 < iVar14) {
                      do {
                        iVar37 = iVar37 + 1;
                        iVar14 = certify(&piStack_398,*pppppppuVar41,iStack_48c,ppppppuStack_3fc,
                                         puVar27,iStack_468,iVar28,ppppppuVar43,iStack_3ac,
                                         ppppppuStack_488,iStack_46c,uStack_458,bVar4,pcStack_454,
                                         ppppppuStack_450,ppppppuStack_3a8,iStack_434,
                                         ppppppuStack_45c,conf,iVar48,uStack_3a0,uStack_3a4,
                                         ppppppuStack_410,uStack_39c,iStack_418);
                        if (iVar14 < 0) goto LAB_00432474;
                        if (iVar14 != 0) {
                          iVar24 = iVar24 + 1;
                          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"\n");
                          iVar14 = (*(code *)PTR_BN_add_word_006a70bc)(iStack_3ac,1);
                          if (iVar14 == 0) goto LAB_00432474;
                          iVar14 = (*(code *)PTR_sk_push_006a6fa8)(iVar17,piStack_398);
                          if (iVar14 == 0) goto LAB_00432b60;
                        }
                        pppppppuVar41 = pppppppuVar41 + 1;
                        iStack_460 = iVar31;
                      } while (iVar31 != iVar37);
                    }
                    iVar14 = (*(code *)PTR_sk_num_006a6e2c)(iVar17);
                    puVar29 = PTR_bio_err_006a6e3c;
                    if (0 < iVar14) {
                      if (iStack_434 != 0) {
LAB_00432bdc:
                        uVar46 = *(undefined4 *)puVar10;
                        uVar19 = (*(code *)PTR_sk_num_006a6e2c)(iVar17);
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (uVar46,"Write out database with %d new entries\n",uVar19);
                        iVar14 = (*(code *)PTR_save_serial_006a70d0)(iVar26,"new",iStack_3ac,0);
                        if ((iVar14 == 0) ||
                           (iVar14 = (*(code *)PTR_save_index_006a7090)(iVar25,"new",ppppppuVar43),
                           iVar14 == 0)) goto LAB_00432474;
                        goto LAB_00432c48;
                      }
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,
                                 "\n%d out of %d certificate requests certified, commit? [y/n]",
                                 iVar24,iStack_460);
                      (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)puVar10,0xb,0,0);
                      auStack_374[0] = auStack_374[0] & 0xffffff;
                      iVar14 = (*(code *)PTR_fgets_006a9ae0)
                                         (auStack_374,10,*(undefined4 *)PTR_stdin_006a9a14);
                      if (iVar14 == 0) {
                        uVar16 = *(undefined4 *)puVar29;
                        pcVar18 = "CERTIFICATION CANCELED: I/O error\n";
                      }
                      else {
                        if ((auStack_374[0]._0_1_ & 0xdf) == 0x59) goto LAB_00432bdc;
                        uVar16 = *(undefined4 *)puVar29;
                        pcVar18 = "CERTIFICATION CANCELED\n";
                      }
                      iVar24 = 0;
                      (*(code *)PTR_BIO_printf_006a6e38)(uVar16,pcVar18);
LAB_004329e0:
                      iVar14 = 0;
                      iVar48 = 0;
                      goto LAB_004306ac;
                    }
LAB_00432c48:
                    if (iVar48 != 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"writing new certificates\n");
                    }
                    for (iVar14 = 0; iVar24 = (*(code *)PTR_sk_num_006a6e2c)(iVar17),
                        iVar14 < iVar24; iVar14 = iVar14 + 1) {
                      piStack_398 = (int *)(*(code *)PTR_sk_value_006a6e24)(iVar17,iVar14);
                      iVar24 = **(int **)(*piStack_398 + 4);
                      puVar29 = (undefined *)(*(int **)(*piStack_398 + 4))[2];
                      uVar20 = (*(code *)PTR_strlen_006a9a24)(ppppppuStack_44c);
                      if (iVar24 == 0) {
                        if (0xf7 < uVar20) goto LAB_00433a14;
                        (*(code *)PTR___memcpy_chk_006a9a48)
                                  (auStack_174,ppppppuStack_44c,uVar20 + 1,0x100);
                        (*(code *)PTR_BUF_strlcat_006a6f68)(auStack_174,&DAT_0063b2b4,0x100);
                        iVar28 = (*(code *)PTR_strlen_006a9a24)(auStack_174);
                        puVar39 = (undefined4 *)(auStack_174 + iVar28);
LAB_00433138:
                        puVar40 = (undefined4 *)((int)puVar39 + 2);
                        auStack_174[iVar28] = 0x30;
                        *(undefined *)((int)puVar39 + 1) = 0x30;
                      }
                      else {
                        if ((uint)((0x7d - iVar24) * 2) <= uVar20) {
LAB_00433a14:
                          uVar16 = *(undefined4 *)puVar10;
                          pcVar18 = "certificate file name too long\n";
                          goto LAB_00432b74;
                        }
                        (*(code *)PTR___memcpy_chk_006a9a48)
                                  (auStack_174,ppppppuStack_44c,uVar20 + 1,0x100);
                        (*(code *)PTR_BUF_strlcat_006a6f68)(auStack_174,&DAT_0063b2b4,0x100);
                        iVar28 = (*(code *)PTR_strlen_006a9a24)(auStack_174);
                        puVar40 = (undefined4 *)(auStack_174 + iVar28);
                        puVar39 = puVar40;
                        if (iVar24 < 1) goto LAB_00433138;
                        if (puVar40 < &iStack_74) {
                          puVar13 = (undefined4 *)(auStack_174 + iVar28 + 2);
                          puVar50 = puVar29;
                          do {
                            puVar40 = puVar13;
                            puVar49 = puVar50 + 1;
                            (*(code *)PTR_BIO_snprintf_006a6f60)
                                      (puVar39,(int)&iStack_74 - (int)puVar39,&DAT_00634b80,*puVar50
                                      );
                            if (puVar49 == puVar29 + iVar24) break;
                            puVar39 = puVar40;
                            puVar13 = (undefined4 *)((int)puVar40 + 2);
                            puVar50 = puVar49;
                          } while (puVar29 + ((uint)((int)&iStack_74 +
                                                    (1 - (int)(auStack_174 + iVar28 + 2))) >> 1) + 1
                                   != puVar49);
                        }
                      }
                      puVar29 = auStack_174;
                      *(undefined *)(puVar40 + 1) = 0;
                      *(undefined *)puVar40 = 0x2e;
                      *(undefined *)((int)puVar40 + 1) = 0x70;
                      *(undefined *)((int)puVar40 + 2) = 0x65;
                      *(undefined *)((int)puVar40 + 3) = 0x6d;
                      if (iVar48 != 0) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar10,"writing %s\n",puVar29);
                      }
                      iVar24 = (*(code *)PTR_BIO_ctrl_006a6e18)(iStack_47c,0x6c,5,puVar29);
                      piVar21 = piStack_398;
                      pcVar53 = (code *)PTR_perror_006a9a80;
                      if (iVar24 < 1) goto LAB_00432e40;
                      if (bVar8) {
                        (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iStack_47c,piStack_398);
                        piVar21 = piStack_398;
                        if (bVar3) goto LAB_00433a2c;
LAB_004331e0:
                        (*(code *)PTR_PEM_write_bio_X509_006a6f20)(ppppppuStack_480,piVar21);
                      }
                      else {
                        (*(code *)PTR_X509_print_006a70c0)(iStack_47c,piStack_398);
                        (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iStack_47c,piVar21);
                        piVar21 = piStack_398;
                        if (!bVar3) {
                          (*(code *)PTR_X509_print_006a70c0)(ppppppuStack_480,piStack_398);
                          goto LAB_004331e0;
                        }
LAB_00433a2c:
                        (*(code *)PTR_i2d_X509_bio_006a6f1c)(ppppppuStack_480,piStack_398);
                      }
                    }
                    iVar14 = (*(code *)PTR_sk_num_006a6e2c)(iVar17);
                    if (iVar14 != 0) {
                      iVar14 = (*(code *)PTR_rotate_serial_006a7118)(iVar26,"new","old");
                      if ((iVar14 == 0) ||
                         (iVar14 = (*(code *)PTR_rotate_index_006a7094)(iVar25,"new","old"),
                         iVar14 == 0)) goto LAB_00432474;
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar10,"Data Base Updated\n");
                    }
LAB_00433214:
                    iVar24 = 0;
                    if (!bVar6) {
LAB_00433714:
                      if (bVar9) {
                        if (ppppppuStack_424 == (undefined4 ******)0x0) {
                          iVar14 = 0;
                          iVar48 = 1;
                          (*(code *)PTR_BIO_printf_006a6e38)
                                    (*(undefined4 *)puVar10,"no input files\n");
                          goto LAB_004306ac;
                        }
                        iVar14 = (*(code *)PTR_load_cert_006a7078)
                                           (*(undefined4 *)puVar10,ppppppuStack_424,3,0,uVar16,
                                            ppppppuStack_424);
                        if ((iVar14 != 0) &&
                           (iVar48 = do_revoke(iVar14,ppppppuVar43,uStack_420,ppppppuStack_41c),
                           0 < iVar48)) {
                          (*(code *)PTR_X509_free_006a6e90)(iVar14);
                          iVar14 = (*(code *)PTR_save_index_006a7090)(iVar25,"new",ppppppuVar43);
                          if ((iVar14 != 0) &&
                             (iVar14 = (*(code *)PTR_rotate_index_006a7094)(iVar25,"new","old"),
                             iVar14 != 0)) {
                            iVar14 = 0;
                            iVar48 = 0;
                            (*(code *)PTR_BIO_printf_006a6e38)
                                      (*(undefined4 *)PTR_bio_err_006a6e3c,"Data Base Updated\n");
                            goto LAB_004306ac;
                          }
                        }
                        goto LAB_00432478;
                      }
                      goto LAB_004329e0;
                    }
                    if ((ppppppuStack_438 == (undefined4 ******)0x0) &&
                       (ppppppuStack_438 =
                             (undefined4 ******)
                             (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"crl_extensions")
                       , ppppppuStack_438 == (undefined4 ******)0x0)) {
                      (*(code *)PTR_ERR_clear_error_006a6ee0)();
                    }
                    else {
                      (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_390,0,0,0,0,1);
                      (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_390,conf);
                      iVar14 = (*(code *)PTR_X509V3_EXT_add_nconf_006a6ebc)
                                         (conf,auStack_390,ppppppuStack_438,0);
                      if (iVar14 == 0) {
                        iVar24 = 0;
                        iVar14 = 0;
                        iVar48 = 1;
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar10,"Error Loading CRL extension section %s\n"
                                   ,ppppppuStack_438);
                        goto LAB_004306ac;
                      }
                    }
                    iVar26 = (*(code *)PTR_NCONF_get_string_006a6ea8)(conf,section,"crlnumber");
                    if (iVar26 == 0) {
                      iVar14 = 0;
                    }
                    else {
                      iVar14 = (*(code *)PTR_load_serial_006a70a0)(iVar26,0,0);
                      if (iVar14 == 0) {
                        iVar24 = 0;
                        iVar48 = 1;
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar10,"error while loading CRL number\n");
                        goto LAB_004306ac;
                      }
                    }
                    if (((iStack_3b8 == 0) && (iStack_3b4 == 0)) && (iStack_400 == 0)) {
                      iVar24 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                         (conf,section,"default_crl_days",&iStack_3b8);
                      if (iVar24 == 0) {
                        iStack_3b8 = 0;
                      }
                      iVar24 = (*(code *)PTR_NCONF_get_number_e_006a6f3c)
                                         (conf,section,"default_crl_hours",&iStack_3b4);
                      if (iVar24 == 0) {
                        iStack_3b4 = 0;
                      }
                      (*(code *)PTR_ERR_clear_error_006a6ee0)();
                      if ((iStack_3b8 == 0) && (iStack_3b4 == 0)) {
                        iVar24 = 0;
                        iVar48 = 1;
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar10,
                                   "cannot lookup how long until the next CRL is issued\n");
                        goto LAB_004306ac;
                      }
                    }
                    if (iVar48 != 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"making CRL\n");
                    }
                    iVar24 = (*(code *)PTR_X509_CRL_new_006a70d8)();
                    if (iVar24 != 0) {
                      uVar19 = (*(code *)PTR_X509_get_subject_name_006a6f00)(iVar15);
                      iVar28 = (*(code *)PTR_X509_CRL_set_issuer_name_006a70dc)(iVar24,uVar19);
                      if ((iVar28 != 0) &&
                         (iVar28 = (*(code *)PTR_ASN1_TIME_new_006a70e0)(), iVar28 != 0)) {
                        (*(code *)PTR_X509_gmtime_adj_006a6f8c)(iVar28,0);
                        (*(code *)PTR_X509_CRL_set_lastUpdate_006a70e4)(iVar24,iVar28);
                        iVar37 = (*(code *)PTR_X509_time_adj_ex_006a6f90)
                                           (iVar28,iStack_3b8,iStack_3b4 * 0xe10 + iStack_400,0);
                        if (iVar37 == 0) {
                          iVar48 = 1;
                          (*(code *)PTR_BIO_puts_006a6f58)
                                    (*(undefined4 *)puVar10,"error setting CRL nextUpdate\n");
                          goto LAB_004306ac;
                        }
                        (*(code *)PTR_X509_CRL_set_nextUpdate_006a70e8)(iVar24,iVar28);
                        (*(code *)PTR_ASN1_TIME_free_006a7050)(iVar28);
                        bVar4 = false;
                        for (iStack_46c = 0;
                            iVar28 = (*(code *)PTR_sk_num_006a6e2c)(ppppppuVar43[1][1]),
                            iStack_46c < iVar28; iStack_46c = iStack_46c + 1) {
                          ppcVar22 = (char **)(*(code *)PTR_sk_value_006a6e24)
                                                        (ppppppuVar43[1][1],iStack_46c);
                          if (**ppcVar22 == 'R') {
                            iVar28 = (*(code *)PTR_X509_REVOKED_new_006a70ec)();
                            if ((iVar28 != 0) &&
                               (iVar37 = make_revoked(iVar28,ppcVar22[2]), iVar37 != 0)) {
                              if (iVar37 == 2) {
                                bVar4 = true;
                              }
                              iVar37 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_3ac,ppcVar22[3]);
                              if (iVar37 != 0) {
                                iVar37 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(iStack_3ac,0);
                                (*(code *)PTR_BN_free_006a701c)(iStack_3ac);
                                iStack_3ac = 0;
                                if (iVar37 != 0) {
                                  (*(code *)PTR_X509_REVOKED_set_serialNumber_006a70f8)
                                            (iVar28,iVar37);
                                  (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar37);
                                  (*(code *)PTR_X509_CRL_add0_revoked_006a70fc)(iVar24,iVar28);
                                  goto LAB_00433454;
                                }
                              }
                            }
                            iVar48 = 1;
                            goto LAB_004306ac;
                          }
LAB_00433454:
                        }
                        (*(code *)PTR_X509_CRL_sort_006a7100)(iVar24);
                        if (iVar48 != 0) {
                          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"signing CRL\n")
                          ;
                        }
                        if (ppppppuStack_438 == (undefined4 ******)0x0) {
                          if (iVar26 == 0) {
                            if (bVar4) goto LAB_004337f4;
LAB_00433698:
                            if (iVar14 != 0) {
                              (*(code *)PTR_BN_free_006a701c)(iVar14);
                            }
                            iVar14 = do_X509_CRL_sign(*(undefined4 *)puVar10,iVar24,iStack_48c,
                                                      puVar27,iStack_468);
                            if ((iVar14 == 0) ||
                               (((*(code *)PTR_PEM_write_bio_X509_CRL_006a7114)
                                           (ppppppuStack_480,iVar24), iVar26 != 0 &&
                                (iVar14 = (*(code *)PTR_rotate_serial_006a7118)(iVar26,"new","old"),
                                iVar14 == 0)))) goto LAB_00432478;
                            goto LAB_00433714;
                          }
                          (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_390,iVar15,0,0,iVar24,0);
                          (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_390,conf);
LAB_004335f0:
                          iVar48 = (*(code *)PTR_BN_to_ASN1_INTEGER_006a70f4)(iVar14,0);
                          if (iVar48 != 0) {
                            (*(code *)PTR_X509_CRL_add1_ext_i2d_006a710c)(iVar24,0x58,iVar48,0,0);
                            (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar48);
                            iVar48 = (*(code *)PTR_BN_add_word_006a70bc)(iVar14,1);
                            if ((iVar48 != 0) &&
                               (iVar48 = (*(code *)PTR_X509_CRL_set_version_006a7108)(iVar24,1),
                               iVar48 != 0)) {
                              if (iVar26 != 0) {
                                iVar48 = (*(code *)PTR_save_serial_006a70d0)(iVar26,"new",iVar14,0);
                                goto joined_r0x00433690;
                              }
                              goto LAB_00433698;
                            }
                          }
                        }
                        else {
                          (*(code *)PTR_X509V3_set_ctx_006a6eb4)(auStack_390,iVar15,0,0,iVar24,0);
                          (*(code *)PTR_X509V3_set_nconf_006a6eb8)(auStack_390,conf);
                          iVar48 = (*(code *)PTR_X509V3_EXT_CRL_add_nconf_006a7104)
                                             (conf,auStack_390,ppppppuStack_438,iVar24);
                          if (iVar48 != 0) {
                            if (iVar26 != 0) goto LAB_004335f0;
LAB_004337f4:
                            iVar48 = (*(code *)PTR_X509_CRL_set_version_006a7108)(iVar24,1);
joined_r0x00433690:
                            if (iVar48 != 0) goto LAB_00433698;
                          }
                        }
                      }
                    }
                  }
                  iVar48 = 1;
                  goto LAB_004306ac;
                }
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar10,"error while loading serial number\n");
              }
LAB_00432228:
              iVar17 = 0;
              iVar24 = 0;
              iVar14 = 0;
              iVar48 = 1;
              goto LAB_004306ac;
            }
            if (iVar48 != 0) {
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"Updating %s ...\n",iVar25);
            }
            iVar17 = (*(code *)PTR_ASN1_UTCTIME_new_006a7030)();
            if (iVar17 != 0) {
              piVar21 = (int *)(*(code *)PTR_X509_gmtime_adj_006a6f8c)(iVar17,0);
              iVar17 = (*(code *)PTR_CRYPTO_malloc_006a7008)(*piVar21 + 1,&DAT_0063526c,0x9da);
              if (iVar17 != 0) {
                (*(code *)PTR_memcpy_006a9aec)(iVar17,piVar21[2],*piVar21);
                puVar29 = PTR_strncmp_006a9970;
                *(undefined *)(iVar17 + *piVar21) = 0;
                iVar24 = (*(code *)puVar29)(iVar17,&DAT_006360a8,2);
                iStack_494 = 0;
                for (ppppppuStack_40c = (undefined4 ******)0x0;
                    iVar26 = (*(code *)PTR_sk_num_006a6e2c)(ppppppuVar43[1][1]),
                    (int)ppppppuStack_40c < iVar26;
                    ppppppuStack_40c = (undefined4 ******)((int)ppppppuStack_40c + 1)) {
                  ppcVar22 = (char **)(*(code *)PTR_sk_value_006a6e24)
                                                (ppppppuVar43[1][1],ppppppuStack_40c);
                  pcVar18 = *ppcVar22;
                  if (*pcVar18 == 'V') {
                    pcVar47 = ppcVar22[1];
                    iVar26 = (*(code *)PTR_strncmp_006a9970)(pcVar47,&DAT_006360a8,2);
                    if (iVar26 < 1) {
                      if (iVar24 < 1) {
LAB_00433de8:
                        iVar26 = (*(code *)PTR_strcmp_006a9b18)(pcVar47,iVar17);
                        if (iVar26 < 1) {
                          *pcVar18 = 'E';
                          pcVar18 = *ppcVar22;
                          goto LAB_00433d6c;
                        }
                      }
                    }
                    else {
                      if (0 < iVar24) goto LAB_00433de8;
                      *pcVar18 = 'E';
                      pcVar18 = *ppcVar22;
LAB_00433d6c:
                      puVar29 = PTR_BIO_printf_006a6e38;
                      iStack_494 = iStack_494 + 1;
                      pcVar18[1] = '\0';
                      (*(code *)puVar29)(*(undefined4 *)puVar10,"%s=Expired\n",ppcVar22[3]);
                    }
                  }
                }
                (*(code *)PTR_ASN1_UTCTIME_free_006a700c)(piVar21);
                (*(code *)PTR_CRYPTO_free_006a6e88)(iVar17);
                if (iStack_494 == 0) {
                  if (iVar48 != 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,"No entries found to mark expired\n");
                  }
                }
                else {
                  iVar17 = (*(code *)PTR_save_index_006a7090)(iVar25,"new",ppppppuVar43);
                  if ((iVar17 == 0) ||
                     (iVar17 = (*(code *)PTR_rotate_index_006a7094)(iVar25,"new","old"), iVar17 == 0
                     )) goto LAB_00431690;
                  if (iVar48 != 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar10,"Done. %d entries marked as expired\n",
                               iStack_494);
                  }
                }
                goto LAB_00431ddc;
              }
              (*(code *)PTR_ASN1_UTCTIME_free_006a700c)(piVar21);
              (*(code *)PTR_CRYPTO_free_006a6e88)(0);
            }
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar10,"Malloc failure\n");
          }
        }
LAB_00431690:
        iVar17 = 0;
        iVar24 = 0;
        iVar14 = 0;
        iVar48 = 1;
        goto LAB_004306ac;
      }
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar10,"variable lookup failed for %s::%s\n",section,"database");
    }
  }
LAB_0043181c:
  iVar17 = 0;
  iVar24 = 0;
  ppppppuVar43 = (undefined4 ******)0x0;
  iVar14 = 0;
  iVar48 = 1;
LAB_004306ac:
  while( true ) {
    (*(code *)PTR_BIO_free_all_006a6e74)(iStack_47c);
    (*(code *)PTR_BIO_free_all_006a6e74)(ppppppuStack_480);
    (*(code *)PTR_BIO_free_all_006a6e74)(iStack_478);
    (*(code *)PTR_BIO_free_all_006a6e74)(iStack_474);
    if (iVar17 != 0) {
      (*(code *)PTR_sk_pop_free_006a7058)(iVar17,PTR_X509_free_006a6e90);
    }
    if (iVar48 != 0) {
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar10);
    }
    (*(code *)PTR_app_RAND_write_file_006a6f4c)(iStack_470,*(undefined4 *)puVar10);
    if ((bVar5) && (ppppppuStack_3bc != (undefined4 ******)0x0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_BN_free_006a701c)(iStack_3ac);
    (*(code *)PTR_BN_free_006a701c)(iVar14);
    (*(code *)PTR_free_index_006a705c)(ppppppuVar43);
    if (iStack_468 != 0) {
      (*(code *)PTR_sk_free_006a6e80)(iStack_468);
    }
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(iStack_48c);
    if (iVar15 != 0) {
      (*(code *)PTR_X509_free_006a6e90)(iVar15);
    }
    (*(code *)PTR_X509_CRL_free_006a7060)(iVar24);
    (*(code *)PTR_NCONF_free_006a6e6c)(conf);
    (*(code *)PTR_NCONF_free_006a6e6c)(extconf);
    (*(code *)PTR_OBJ_cleanup_006a6e98)();
    if (iStack_74 == *(int *)puVar11) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    ppppppuVar51 = ppppppuVar43;
LAB_00430638:
    if (iStack_3b0 < 1) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar10,"error loading the config file \'%s\'\n",ppppppuVar51);
    }
    else {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar10,"error on line %ld of config file \'%s\'\n",iStack_3b0,
                 ppppppuVar51);
    }
    if (ppppppuVar43 != (undefined4 ******)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppppppuVar43);
    }
LAB_00430670:
    iStack_470 = 0;
LAB_00430674:
    ppppppuVar43 = (undefined4 ******)0x0;
LAB_00430680:
    iStack_47c = 0;
    ppppppuStack_480 = (undefined4 ******)0x0;
    iStack_478 = 0;
    iStack_474 = 0;
LAB_00430690:
    iVar17 = 0;
    iVar24 = 0;
    iStack_48c = 0;
    iVar15 = 0;
    bVar5 = false;
    iVar14 = 0;
    iVar48 = 1;
  }
  return iVar48;
}

