
/* WARNING: Could not reconcile some variable overlaps */

undefined * do_responder_isra_0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 *puVar5;
  SSL_METHOD *pSVar6;
  int iVar7;
  char **ppcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  char *pcVar15;
  undefined *puVar16;
  undefined4 uVar17;
  undefined **ppuVar18;
  undefined *unaff_s1;
  int iVar19;
  undefined *puVar20;
  undefined *puVar21;
  int iVar22;
  int unaff_s3;
  char *pcVar23;
  undefined *unaff_s4;
  undefined *puVar24;
  char *pcVar25;
  undefined **ppuVar26;
  undefined *puVar27;
  undefined *puVar28;
  undefined **unaff_s7;
  code *pcVar29;
  char *pcStack_6c8;
  undefined *puStack_6c4;
  undefined *puStack_6c0;
  undefined *puStack_6bc;
  undefined *puStack_6b8;
  char *pcStack_6b4;
  int iStack_6b0;
  undefined *puStack_6ac;
  undefined *puStack_6a8;
  undefined *puStack_6a4;
  char *pcStack_6a0;
  char *pcStack_69c;
  undefined *puStack_698;
  int iStack_694;
  undefined4 uStack_690;
  int iStack_68c;
  undefined4 uStack_688;
  undefined *puStack_67c;
  int iStack_678;
  int iStack_674;
  undefined *puStack_670;
  undefined *puStack_66c;
  undefined *puStack_668;
  undefined *puStack_664;
  undefined *puStack_660;
  int iStack_65c;
  undefined4 uStack_658;
  int iStack_650;
  int iStack_64c;
  uint uStack_644;
  uint uStack_640;
  int iStack_63c;
  int iStack_638;
  undefined *puStack_630;
  undefined *puStack_62c;
  int iStack_628;
  int iStack_624;
  int iStack_620;
  undefined *puStack_61c;
  undefined *puStack_618;
  int iStack_610;
  undefined *puStack_5fc;
  undefined *puStack_5f8;
  undefined *puStack_5f4;
  undefined4 uStack_5f0;
  undefined4 uStack_5ec;
  int iStack_5e8;
  int iStack_5e4;
  undefined4 uStack_5e0;
  int iStack_5dc;
  int iStack_5d8;
  undefined4 uStack_5d4;
  int iStack_5d0;
  int iStack_5cc;
  undefined4 uStack_5c8;
  undefined4 uStack_5c4;
  undefined4 uStack_5c0;
  undefined4 uStack_5bc;
  undefined4 uStack_5b8;
  undefined4 uStack_5b4;
  undefined4 auStack_5b0 [4];
  undefined auStack_5a0 [68];
  int iStack_55c;
  undefined *puStack_558;
  undefined4 uStack_554;
  undefined **ppuStack_550;
  int iStack_54c;
  undefined *puStack_548;
  int iStack_544;
  undefined *puStack_540;
  undefined **ppuStack_53c;
  char *pcStack_538;
  code *pcStack_534;
  undefined **ppuStack_520;
  undefined *puStack_518;
  undefined **ppuStack_510;
  int iStack_50c;
  uint uStack_504;
  undefined *puStack_500;
  undefined *puStack_4fc;
  undefined4 uStack_4f8;
  undefined *apuStack_4f4 [32];
  int iStack_474;
  undefined *puStack_470;
  undefined *puStack_46c;
  undefined4 *puStack_468;
  int iStack_464;
  undefined *puStack_460;
  undefined *puStack_45c;
  undefined4 *puStack_458;
  undefined **ppuStack_454;
  int iStack_434;
  undefined4 uStack_430;
  undefined *local_42c [256];
  int local_2c;
  
  puStack_45c = PTR___stack_chk_guard_006a9ae8;
  ppuStack_550 = (undefined **)0x0;
  puVar16 = (undefined *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_BIO_ctrl_006a6e18)(param_3,0x65,0);
  puStack_470 = PTR_bio_err_006a6e3c;
  if (iVar2 < 1) {
    pcStack_538 = "Error accepting connection\n";
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puStack_470);
    puVar3 = (undefined *)0x0;
  }
  else {
    unaff_s7 = local_42c;
    unaff_s1 = (undefined *)(*(code *)PTR_BIO_pop_006a79c8)(param_3);
    puStack_470 = (undefined *)0x0;
    *param_2 = unaff_s1;
    unaff_s4 = &DAT_006442c4;
    param_2 = (undefined4 *)&DAT_0000000d;
    unaff_s3 = 10;
    do {
      puVar16 = &DAT_00000400;
      pcStack_538 = (char *)unaff_s7;
      iVar2 = (*(code *)PTR_BIO_gets_006a74d4)(unaff_s1,unaff_s7,0x400);
      if (iVar2 < 1) {
        puVar3 = (undefined *)0x1;
        goto LAB_0047184c;
      }
      if (puStack_470 == (undefined *)0x0) {
        puVar16 = &SUB_00000004;
        iVar2 = (*(code *)PTR_strncmp_006a9970)(unaff_s7,&DAT_006442c4,4);
        if (iVar2 != 0) {
          pcStack_538 = "Invalid request\n";
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
          puVar3 = (undefined *)0x1;
          goto LAB_0047184c;
        }
      }
    } while ((local_42c[0]._0_1_ != '\r') &&
            (puStack_470 = (undefined *)0x1, local_42c[0]._0_1_ != '\n'));
    ppuStack_550 = (undefined **)0x0;
    pcStack_538 = PTR_d2i_OCSP_REQUEST_006a7d90;
    puVar16 = unaff_s1;
    puStack_470 = (undefined *)
                  (*(code *)PTR_ASN1_d2i_bio_006a71c4)
                            (PTR_OCSP_REQUEST_new_006a777c,PTR_d2i_OCSP_REQUEST_006a7d90,unaff_s1);
    puVar21 = PTR_bio_err_006a6e3c;
    if (puStack_470 == (undefined *)0x0) {
      pcStack_538 = "Error parsing OCSP request\n";
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar21);
      puVar3 = (undefined *)0x1;
      *param_1 = 0;
      unaff_s1 = puVar21;
    }
    else {
      *param_1 = puStack_470;
      puVar3 = (undefined *)0x1;
    }
  }
LAB_0047184c:
  if (local_2c == *(int *)puStack_45c) {
    return puVar3;
  }
  iStack_50c = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_540 = PTR___stack_chk_guard_006a9ae8;
  puStack_518 = &_gp;
  iStack_474 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_46c = unaff_s1;
  puStack_468 = param_2;
  iStack_464 = unaff_s3;
  puStack_460 = unaff_s4;
  puStack_458 = param_1;
  ppuStack_454 = unaff_s7;
  iVar2 = (*(code *)PTR_BIO_new_connect_006a7d94)(puVar16);
  if (iVar2 == 0) {
    puStack_558 = (undefined *)0x0;
    pcVar15 = "Error creating connect BIO\n";
    (**(code **)(puStack_518 + -0x7fa8))(iStack_50c);
    goto LAB_00471ac8;
  }
  (**(code **)(puStack_518 + -0x7fc8))(iVar2,100,1,&_gp);
  if (iStack_434 != 1) {
    iStack_434 = 0;
LAB_004719f8:
    puStack_500 = (undefined *)0x0;
    if (local_42c[0] == (undefined *)0xffffffff) {
      iVar4 = (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x65,0,0);
      if (iVar4 < 1) {
LAB_00471ed8:
        (**(code **)(puStack_518 + -0x7e88))(iStack_50c,"Error connecting BIO\n");
      }
      else {
        iVar4 = (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x69,0,&uStack_504);
        if (iVar4 < 0) {
LAB_00471a78:
          puVar5 = *(undefined4 **)(puStack_518 + -0x7fa4);
          goto LAB_00471a7c;
        }
LAB_00471b40:
        ppuStack_550 = (undefined **)
                       (**(code **)(puStack_518 + -0x7048))(iVar2,ppuStack_550,0,0xffffffff);
        if (ppuStack_550 != (undefined **)0x0) {
          for (iVar4 = 0; iVar7 = (**(code **)(puStack_518 + -0x7fb4))(uStack_430), iVar4 < iVar7;
              iVar4 = iVar4 + 1) {
            iVar7 = (**(code **)(puStack_518 + -0x7fbc))(uStack_430,iVar4);
            pcVar15 = *(char **)(iVar7 + 4);
            iVar7 = (**(code **)(puStack_518 + -0x7044))
                              (ppuStack_550,pcVar15,*(undefined4 *)(iVar7 + 8));
            if (iVar7 == 0) goto LAB_00471cd0;
          }
          pcVar15 = pcStack_538;
          iVar4 = (**(code **)(puStack_518 + -0x7040))(ppuStack_550);
          if (iVar4 != 0) {
            ppuStack_510 = &puStack_4fc;
            unaff_s7 = &puStack_500;
            pcStack_538 = (char *)apuStack_4f4;
            uStack_430 = 0x8000001f;
            do {
              if (local_42c[0] == (undefined *)0xffffffff) goto LAB_00471d38;
              pcVar15 = (char *)ppuStack_550;
              iVar4 = (**(code **)(puStack_518 + -0x703c))(unaff_s7);
              if (iVar4 != -1) goto LAB_00471cd0;
              (**(code **)(puStack_518 + -0x53ec))(pcStack_538,0,0x80);
              iVar4 = (**(code **)(puStack_518 + -0x5340))(uStack_504);
              pcVar29 = *(code **)(puStack_518 + -0x7578);
              uStack_4f8 = 0;
              puStack_4fc = local_42c[0];
              apuStack_4f4[iVar4] =
                   (undefined *)(1 << (uStack_504 & 0x1f) | (uint)apuStack_4f4[iVar4]);
              iVar4 = (*pcVar29)(iVar2,1);
              if (iVar4 == 0) {
                iVar4 = (**(code **)(puStack_518 + -0x7578))(iVar2,2);
                if (iVar4 == 0) {
                  pcVar15 = "Unexpected retry condition\n";
                  (**(code **)(puStack_518 + -0x7e88))(iStack_50c);
                  goto LAB_00471cd0;
                }
                ppuStack_520 = ppuStack_510;
                iVar4 = (**(code **)(puStack_518 + -0x531c))(uStack_504 + 1,0,pcStack_538,0);
              }
              else {
                ppuStack_520 = ppuStack_510;
                iVar4 = (**(code **)(puStack_518 + -0x531c))(uStack_504 + 1,pcStack_538,0,0);
              }
              if (iVar4 == 0) {
                pcVar15 = "Timeout on request\n";
                (**(code **)(puStack_518 + -0x7e88))(iStack_50c);
                goto LAB_00471cd0;
              }
            } while (iVar4 != -1);
            pcVar15 = "Select error\n";
            (**(code **)(puStack_518 + -0x7e88))(iStack_50c);
          }
LAB_00471cd0:
          pcVar29 = *(code **)(puStack_518 + -0x7038);
          goto LAB_00471cd4;
        }
      }
    }
    else {
      (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x66,1);
      iVar4 = (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x65,0,0);
      if (0 < iVar4) {
        iVar4 = (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x69,0,&uStack_504);
        if (-1 < iVar4) goto LAB_00471b40;
        puVar5 = *(undefined4 **)(puStack_518 + -0x7fa4);
LAB_00471a7c:
        pcVar15 = "Can\'t get connection fd\n";
        (**(code **)(puStack_518 + -0x7e88))(*puVar5);
        puStack_558 = puStack_500;
        if (puStack_500 == (undefined *)0x0) goto LAB_00471eb4;
        goto LAB_00471a9c;
      }
      iVar4 = (**(code **)(puStack_518 + -0x7578))(iVar2,8);
      if (iVar4 == 0) goto LAB_00471ed8;
      iVar4 = (**(code **)(puStack_518 + -0x7fc8))(iVar2,0x69,0,&uStack_504);
      if (iVar4 < 0) goto LAB_00471a78;
      (**(code **)(puStack_518 + -0x53ec))(apuStack_4f4,0,0x80);
      iVar4 = (**(code **)(puStack_518 + -0x5340))(uStack_504);
      pcVar29 = *(code **)(puStack_518 + -0x531c);
      uStack_4f8 = 0;
      puStack_4fc = local_42c[0];
      ppuStack_520 = &puStack_4fc;
      apuStack_4f4[iVar4] = (undefined *)(1 << (uStack_504 & 0x1f) | (uint)apuStack_4f4[iVar4]);
      iVar4 = (*pcVar29)(uStack_504 + 1,0,apuStack_4f4,0);
      if (iVar4 != 0) goto LAB_00471b40;
      (**(code **)(puStack_518 + -0x7e88))(iStack_50c,"Timeout on connect\n");
    }
LAB_00471eb4:
    puVar5 = *(undefined4 **)(puStack_518 + -0x7fa4);
    goto LAB_00471eb8;
  }
  pSVar6 = SSLv23_client_method();
  iStack_434 = (**(code **)(puStack_518 + -0x7540))(pSVar6);
  if (iStack_434 != 0) {
    (**(code **)(puStack_518 + -0x7684))(iStack_434,0x21,4,0);
    uVar9 = (**(code **)(puStack_518 + -0x7034))(iStack_434,1);
    iVar2 = (**(code **)(puStack_518 + -0x791c))(uVar9,iVar2);
    goto LAB_004719f8;
  }
  puStack_558 = (undefined *)0x0;
  pcVar15 = "Error creating SSL context.\n";
  (**(code **)(puStack_518 + -0x7fa8))(iStack_50c);
LAB_00471aa4:
  (**(code **)(puStack_518 + -0x7f6c))(iVar2);
LAB_00471ab4:
  unaff_s3 = iVar2;
  if (iStack_434 != 0) {
    (**(code **)(puStack_518 + -0x7550))(iStack_434);
  }
LAB_00471ac8:
  if (iStack_474 == *(int *)puStack_540) {
    return puStack_558;
  }
  pcStack_534 = ocsp_main;
  (**(code **)(puStack_518 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  puVar16 = PTR_bio_err_006a6e3c;
  uStack_5f0 = 0xffffffff;
  puStack_548 = local_42c[0];
  puStack_5f4 = &DAT_0063b2b4;
  puStack_5fc = (undefined *)0x0;
  puStack_5f8 = (undefined *)0x0;
  uStack_5ec = 0;
  iStack_5e8 = 0;
  iStack_5e4 = 0;
  iStack_55c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = *(int *)PTR_bio_err_006a6e3c;
  uStack_554 = uStack_430;
  iStack_54c = unaff_s3;
  iStack_544 = iStack_434;
  ppuStack_53c = unaff_s7;
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(int *)puVar16 = iVar2;
  }
  iVar2 = load_config(iVar2,0);
  if (iVar2 != 0) {
    (*(code *)PTR_SSL_load_error_strings_006a7588)();
    (*(code *)PTR_SSL_library_init_006a7898)();
    uStack_688 = (*(code *)PTR_sk_new_null_006a6fa4)();
    uStack_690 = (*(code *)PTR_sk_new_null_006a6fa4)();
    pcVar25 = *(char **)((int)pcVar15 + 4);
    if ((pcVar25 != (char *)0x0) && (*pcVar25 == '-')) {
      iStack_6b0 = 0;
      puStack_6a4 = (undefined *)0x0;
      puStack_6a8 = (undefined *)0x0;
      iStack_64c = -1;
      puVar21 = (undefined *)0x0;
      iStack_678 = -1;
      puVar28 = (undefined *)0x0;
      iStack_620 = -1;
      puStack_668 = (undefined *)0x0;
      iVar2 = 0x630000;
      iStack_63c = 0;
      pcVar23 = "-check_ss_sig";
      iStack_624 = 300;
      uStack_644 = 0;
      puVar24 = &UNK_006443fc;
      uStack_640 = 0;
      uStack_658 = 0;
      pcStack_6b4 = (char *)0x0;
      puStack_62c = (undefined *)0x0;
      iStack_674 = 1;
      puStack_660 = (undefined *)0x0;
      puStack_618 = (undefined *)0x0;
      puStack_61c = (undefined *)0x0;
      iStack_650 = 0;
      iStack_65c = 0;
      iStack_68c = 0;
      iStack_694 = 0;
      iStack_628 = 0;
      puStack_6bc = (undefined *)0x0;
      puStack_67c = (undefined *)0x0;
      puStack_670 = (undefined *)0x0;
      puStack_664 = (undefined *)0x0;
      puStack_66c = (undefined *)0x0;
      puStack_630 = (undefined *)0x0;
      puStack_6ac = (undefined *)0x0;
      puStack_6c0 = (undefined *)0x0;
      puStack_6c4 = (undefined *)0x0;
      pcStack_6c8 = "-check_ss_sig";
      puStack_6b8 = (undefined *)0x0;
      iStack_638 = -1;
      pcStack_6a0 = "certificate";
      pcStack_69c = "issuer certificate";
      goto LAB_004723cc;
    }
    puStack_6a4 = (undefined *)0x0;
    puStack_6a8 = (undefined *)0x0;
    puVar20 = (undefined *)0x0;
    puStack_668 = (undefined *)0x0;
    iStack_64c = -1;
    puVar28 = (undefined *)0x0;
    iStack_678 = -1;
    iStack_620 = -1;
    iStack_63c = 0;
    uStack_644 = 0;
    iStack_624 = 300;
    uStack_640 = 0;
    uStack_658 = 0;
    iStack_638 = -1;
    pcStack_6b4 = (char *)0x0;
    puStack_62c = (undefined *)0x0;
    iStack_674 = 1;
    bVar1 = false;
    puStack_660 = (undefined *)0x0;
    puStack_618 = (undefined *)0x0;
    puStack_61c = (undefined *)0x0;
    iStack_650 = 0;
    iStack_65c = 0;
    iStack_68c = 0;
    iStack_694 = 0;
    iStack_628 = 0;
    puStack_6bc = (undefined *)0x0;
    puStack_67c = (undefined *)0x0;
    puStack_670 = (undefined *)0x0;
    puStack_664 = (undefined *)0x0;
    puStack_66c = (undefined *)0x0;
    puStack_630 = (undefined *)0x0;
    puStack_6ac = (undefined *)0x0;
    puStack_6c0 = (undefined *)0x0;
    puStack_6c4 = (undefined *)0x0;
    puVar27 = (undefined *)0x0;
    goto LAB_004725b0;
  }
  ppuVar18 = (undefined **)0x0;
  uStack_690 = 0;
  puStack_698 = (undefined *)0x0;
  uStack_688 = 0;
  pcVar23 = (char *)0x0;
  puStack_6bc = (undefined *)0x0;
  puVar24 = (undefined *)0x1;
  iStack_6b0 = 0;
  puVar20 = (undefined *)0x0;
  puStack_6b8 = (undefined *)0x0;
  pcVar25 = (char *)0x0;
  puStack_6a8 = (undefined *)0x0;
  iVar2 = 0;
  pcStack_69c = (char *)0x0;
  puVar28 = (undefined *)0x0;
  puStack_6ac = (undefined *)0x0;
  pcStack_6c8 = (char *)0x0;
  iStack_68c = 0;
  iStack_694 = 0;
  puStack_6c0 = (undefined *)0x0;
  puStack_6c4 = (undefined *)0x0;
LAB_00472078:
  do {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar16);
    (*(code *)PTR_X509_free_006a6e90)(pcStack_6c8);
    (*(code *)PTR_X509_STORE_free_006a7274)(pcVar25);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(pcStack_69c);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(puStack_6a8);
    (*(code *)PTR_X509_free_006a6e90)(iStack_694);
    (*(code *)PTR_X509_free_006a6e90)(iStack_68c);
    (*(code *)PTR_X509_free_006a6e90)(puStack_6ac);
    (*(code *)PTR_X509_free_006a6e90)(pcVar23);
    free_index(puStack_698);
    (*(code *)PTR_BIO_free_all_006a6e74)(iStack_5e4);
    (*(code *)PTR_BIO_free_all_006a6e74)(puStack_6b8);
    (*(code *)PTR_BIO_free_006a6e70)(iStack_6b0);
    (*(code *)PTR_OCSP_REQUEST_free_006a7774)(iStack_5e8);
    (*(code *)PTR_OCSP_RESPONSE_free_006a7778)(ppuVar18);
    (*(code *)PTR_OCSP_BASICRESP_free_006a7db0)(iVar2);
    (*(code *)PTR_sk_free_006a6e80)(uStack_688);
    (*(code *)PTR_sk_free_006a6e80)(uStack_690);
    (*(code *)PTR_sk_pop_free_006a7058)(puStack_6bc,PTR_X509_free_006a6e90);
    (*(code *)PTR_sk_pop_free_006a7058)(puVar20,PTR_X509_free_006a6e90);
    (*(code *)PTR_sk_pop_free_006a7058)(uStack_5ec,PTR_X509V3_conf_free_006a7b4c);
    if (puStack_6c4 != (undefined *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_6c4);
    }
    if (puStack_6c0 != (undefined *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_6c0);
    }
    if (puVar28 != (undefined *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar28);
    }
    if (iStack_55c == *(int *)puVar3) {
      return puVar24;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    iStack_638 = (int)puStack_698;
LAB_00474214:
    iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_cert_checks");
    if (iVar4 == 0) {
      uStack_640 = uStack_640 | 0x100;
      bVar1 = false;
    }
    else {
      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_explicit");
      if (iVar4 == 0) {
        uStack_640 = uStack_640 | 0x20;
        bVar1 = false;
      }
      else {
        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-trust_other");
        if (iVar4 == 0) {
          uStack_640 = uStack_640 | 0x200;
          bVar1 = false;
        }
        else {
          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_intern");
          if (iVar4 == 0) {
            uStack_640 = uStack_640 | 2;
            bVar1 = false;
          }
          else {
            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-text");
            if (iVar4 == 0) {
              bVar1 = false;
              iStack_650 = 1;
              iStack_65c = 1;
            }
            else {
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-req_text");
              if (iVar4 == 0) {
                bVar1 = false;
                iStack_65c = 1;
              }
              else {
                iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-resp_text");
                if (iVar4 == 0) {
                  bVar1 = false;
                  iStack_650 = 1;
                }
                else {
                  iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-reqin");
                  puVar21 = puVar20;
                  if (iVar4 == 0) {
                    ppuVar26 = ppuVar18 + 1;
                    if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                    bVar1 = false;
                    ppuVar18 = ppuVar18 + 1;
                    puStack_6ac = *ppuVar26;
                  }
                  else {
                    iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-respin");
                    if (iVar4 == 0) {
                      ppuVar26 = ppuVar18 + 1;
                      if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                      bVar1 = false;
                      ppuVar18 = ppuVar18 + 1;
                      puStack_630 = *ppuVar26;
                    }
                    else {
                      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-signer");
                      if (iVar4 == 0) {
                        ppuVar26 = ppuVar18 + 1;
                        if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                        bVar1 = false;
                        ppuVar18 = ppuVar18 + 1;
                        puStack_670 = *ppuVar26;
                      }
                      else {
                        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-VAfile");
                        if (iVar4 == 0) {
                          ppuVar26 = ppuVar18 + 1;
                          if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                          bVar1 = false;
                          uStack_640 = uStack_640 | 0x200;
                          ppuVar18 = ppuVar18 + 1;
                          puStack_62c = *ppuVar26;
                        }
                        else {
                          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-sign_other");
                          if (iVar4 == 0) {
                            ppuVar26 = ppuVar18 + 1;
                            if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                            bVar1 = false;
                            ppuVar18 = ppuVar18 + 1;
                            puStack_660 = *ppuVar26;
                          }
                          else {
                            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-verify_other");
                            if (iVar4 == 0) {
                              ppuVar26 = ppuVar18 + 1;
                              if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                              bVar1 = false;
                              ppuVar18 = ppuVar18 + 1;
                              puStack_62c = *ppuVar26;
                            }
                            else {
                              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-CAfile");
                              if (iVar4 == 0) {
                                ppuVar26 = ppuVar18 + 1;
                                if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                                bVar1 = false;
                                ppuVar18 = ppuVar18 + 1;
                                puStack_61c = *ppuVar26;
                              }
                              else {
                                iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-CApath");
                                if (iVar4 == 0) {
                                  ppuVar26 = ppuVar18 + 1;
                                  if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                                  bVar1 = false;
                                  ppuVar18 = ppuVar18 + 1;
                                  puStack_618 = *ppuVar26;
                                }
                                else {
                                  iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-validity_period")
                                  ;
                                  if (iVar4 == 0) {
                                    if (ppuVar18[1] == (undefined *)0x0) goto LAB_00472528;
                                    ppuVar26 = ppuVar18 + 1;
                                    iStack_624 = (*(code *)PTR_strtol_006a9958)(ppuVar18[1],0,10);
                                    if (-1 < iStack_624) goto LAB_00472424;
                                    (*(code *)PTR_BIO_printf_006a6e38)
                                              (*(undefined4 *)puVar16,"Illegal validity period %s\n"
                                               ,ppuVar18[1]);
                                    bVar1 = true;
                                    ppuVar18 = ppuVar26;
                                  }
                                  else {
                                    iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-status_age");
                                    if (iVar4 == 0) {
                                      if (ppuVar18[1] == (undefined *)0x0) goto LAB_00472528;
                                      ppuVar26 = ppuVar18 + 1;
                                      iStack_620 = (*(code *)PTR_strtol_006a9958)(ppuVar18[1],0,10);
                                      if (-1 < iStack_620) goto LAB_00472424;
                                      (*(code *)PTR_BIO_printf_006a6e38)
                                                (*(undefined4 *)puVar16,"Illegal validity age %s\n",
                                                 ppuVar18[1]);
                                      bVar1 = true;
                                      ppuVar18 = ppuVar26;
                                    }
                                    else {
                                      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-signkey");
                                      if (iVar4 == 0) {
                                        ppuVar26 = ppuVar18 + 1;
                                        if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                                        bVar1 = false;
                                        ppuVar18 = ppuVar18 + 1;
                                        puStack_67c = *ppuVar26;
                                      }
                                      else {
                                        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-reqout");
                                        if (iVar4 == 0) {
                                          ppuVar26 = ppuVar18 + 1;
                                          if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                                          bVar1 = false;
                                          ppuVar18 = ppuVar18 + 1;
                                          puStack_66c = *ppuVar26;
                                        }
                                        else {
                                          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-respout")
                                          ;
                                          if (iVar4 == 0) {
                                            ppuVar26 = ppuVar18 + 1;
                                            if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                                            bVar1 = false;
                                            ppuVar18 = ppuVar18 + 1;
                                            puStack_664 = *ppuVar26;
                                          }
                                          else {
                                            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-path");
                                            if (iVar4 == 0) {
                                              ppuVar26 = ppuVar18 + 1;
                                              if (*ppuVar26 == (undefined *)0x0) goto LAB_00472528;
                                              bVar1 = false;
                                              ppuVar18 = ppuVar18 + 1;
                                              puStack_5f4 = *ppuVar26;
                                            }
                                            else {
                                              iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                (pcVar25,"-issuer");
                                              if (iVar4 != 0) {
                                                iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                  (pcVar25,"-cert");
                                                if (iVar4 == 0) {
                                                  if (ppuVar18[1] == (undefined *)0x0)
                                                  goto LAB_00472528;
                                                  (*(code *)PTR_X509_free_006a6e90)(iStack_68c);
                                                  iStack_68c = load_cert(*(undefined4 *)puVar16,
                                                                         ppuVar18[1],3,0,0,
                                                                         pcStack_6a0);
                                                  if (iStack_68c == 0) goto LAB_00473514;
                                                  if (iStack_6b0 == 0) {
                                                    iStack_6b0 = (*(code *)PTR_EVP_sha1_006a75d0)();
                                                  }
                                                  if (iStack_694 == 0) {
LAB_00474870:
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar16,
                                                               "No issuer certificate specified\n");
                                                    goto LAB_00473514;
                                                  }
                                                  if ((iStack_5e8 != 0) ||
                                                     (iStack_5e8 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a777c)(), iStack_5e8 != 0)
                                                  ) {
                                                    iVar7 = (*(code *)PTR_OCSP_cert_to_id_006a7780)
                                                                      (iStack_6b0,iStack_68c,
                                                                       iStack_694);
joined_r0x0047496c:
                                                    if (iVar7 != 0) {
                                                      iVar4 = (*(code *)PTR_sk_push_006a6fa8)
                                                                        (uStack_690,iVar7);
                                                      if ((iVar4 != 0) &&
                                                         (iVar4 = (*(code *)
                                                  PTR_OCSP_request_add0_id_006a7784)
                                                            (iStack_5e8,iVar7), iVar4 != 0)) {
                                                    iVar4 = (*(code *)PTR_sk_push_006a6fa8)
                                                                      (uStack_688,ppuVar18[1]);
                                                    if (iVar4 != 0) {
                                                      bVar1 = false;
                                                      ppuVar18 = ppuVar18 + 1;
                                                      goto LAB_004723ac;
                                                    }
                                                    goto LAB_00473514;
                                                  }
                                                  }
                                                  }
                                                }
                                                else {
                                                  iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                    (pcVar25,"-serial");
                                                  if (iVar4 != 0) {
                                                    iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar25,"-index");
                                                    if (iVar4 == 0) {
                                                      ppuVar26 = ppuVar18 + 1;
                                                      if (*ppuVar26 == (undefined *)0x0)
                                                      goto LAB_00472528;
                                                      bVar1 = false;
                                                      ppuVar18 = ppuVar18 + 1;
                                                      puStack_668 = *ppuVar26;
                                                    }
                                                    else if (((pcVar25[1] == 'C') &&
                                                             (pcVar25[2] == 'A')) &&
                                                            (pcVar25[3] == '\0')) {
                                                      ppuVar26 = ppuVar18 + 1;
                                                      if (*ppuVar26 == (undefined *)0x0)
                                                      goto LAB_00472528;
                                                      bVar1 = false;
                                                      ppuVar18 = ppuVar18 + 1;
                                                      puStack_6a8 = *ppuVar26;
                                                    }
                                                    else {
                                                      iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar25,"-nmin");
                                                      if (iVar4 == 0) {
                                                        if (ppuVar18[1] == (undefined *)0x0) {
                                                          bVar1 = false;
                                                        }
                                                        else {
                                                          puStack_6a4 = (undefined *)
                                                                        (*(code *)
                                                  PTR_strtol_006a9958)(ppuVar18[1],0,10);
                                                  if ((int)puStack_6a4 < 0) {
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*(undefined4 *)puVar16,
                                                               "Illegal update period %s\n",
                                                               ppuVar18[1]);
                                                    bVar1 = true;
                                                    ppuVar18 = ppuVar18 + 1;
                                                  }
                                                  else {
                                                    bVar1 = false;
                                                    ppuVar18 = ppuVar18 + 1;
                                                  }
                                                  }
                                                  if (iStack_64c != -1) goto LAB_00472528;
                                                  iStack_64c = 0;
                                                  }
                                                  else {
                                                    iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar25,"-nrequest");
                                                    if (iVar4 == 0) {
                                                      if (ppuVar18[1] == (undefined *)0x0)
                                                      goto LAB_00472528;
                                                      ppuVar26 = ppuVar18 + 1;
                                                      iStack_678 = (*(code *)PTR_strtol_006a9958)
                                                                             (ppuVar18[1],0,10);
                                                      if (-1 < iStack_678) goto LAB_00472424;
                                                      (*(code *)PTR_BIO_printf_006a6e38)
                                                                (*(undefined4 *)puVar16,
                                                                 "Illegal accept count %s\n",
                                                                 ppuVar18[1]);
                                                      bVar1 = true;
                                                      ppuVar18 = ppuVar26;
                                                    }
                                                    else {
                                                      iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (pcVar25,"-ndays");
                                                      if (iVar4 == 0) {
                                                        if (ppuVar18[1] == (undefined *)0x0)
                                                        goto LAB_00472528;
                                                        ppuVar26 = ppuVar18 + 1;
                                                        iStack_64c = (*(code *)PTR_strtol_006a9958)
                                                                               (ppuVar18[1],0,10);
                                                        if (-1 < iStack_64c) goto LAB_00472424;
                                                        (*(code *)PTR_BIO_printf_006a6e38)
                                                                  (*(undefined4 *)puVar16,
                                                                   "Illegal update period %s\n",
                                                                   ppuVar18[1]);
                                                        bVar1 = true;
                                                        ppuVar18 = ppuVar26;
                                                      }
                                                      else {
                                                        iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                          (pcVar25,"-rsigner");
                                                        if (iVar4 == 0) {
                                                          ppuVar26 = ppuVar18 + 1;
                                                          if (*ppuVar26 == (undefined *)0x0)
                                                          goto LAB_00472528;
                                                          ppuVar18 = ppuVar18 + 1;
                                                          bVar1 = false;
                                                          puStack_6bc = *ppuVar26;
                                                        }
                                                        else {
                                                          iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                            (pcVar25,"-rkey");
                                                          if (iVar4 == 0) {
                                                            ppuVar26 = ppuVar18 + 1;
                                                            if (*ppuVar26 == (undefined *)0x0)
                                                            goto LAB_00472528;
                                                            ppuVar18 = ppuVar18 + 1;
                                                            bVar1 = false;
                                                            puStack_6b8 = *ppuVar26;
                                                          }
                                                          else {
                                                            iVar4 = (*(code *)PTR_strcmp_006a9b18)
                                                                              (pcVar25,"-rother");
                                                            if (iVar4 == 0) {
                                                              ppcVar8 = ppuVar18 + 1;
                                                              if (*ppcVar8 == (char *)0x0) {
                                                                bVar1 = true;
                                                              }
                                                              else {
                                                                ppuVar18 = ppuVar18 + 1;
                                                                bVar1 = false;
                                                                pcStack_6b4 = *ppcVar8;
                                                              }
                                                            }
                                                            else {
                                                              iStack_6b0 = (*(code *)
                                                  PTR_EVP_get_digestbyname_006a6f2c)(pcVar25 + 1);
                                                  bVar1 = iStack_6b0 == 0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_004723ac;
                                                  }
                                                  puStack_698 = ppuVar18[1];
                                                  if (puStack_698 == (undefined *)0x0)
                                                  goto LAB_00472528;
                                                  if (iStack_6b0 == 0) {
                                                    iStack_6b0 = (*(code *)PTR_EVP_sha1_006a75d0)();
                                                    puStack_698 = ppuVar18[1];
                                                  }
                                                  if (iStack_694 == 0) goto LAB_00474870;
                                                  if ((iStack_5e8 != 0) ||
                                                     (iStack_5e8 = (*(code *)
                                                  PTR_OCSP_REQUEST_new_006a777c)(), iStack_5e8 != 0)
                                                  ) {
                                                    uVar9 = (*(code *)
                                                  PTR_X509_get_subject_name_006a6f00)(iStack_694);
                                                  uVar10 = (*(code *)
                                                  PTR_X509_get0_pubkey_bitstr_006a7e28)(iStack_694);
                                                  iVar4 = (*(code *)PTR_s2i_ASN1_INTEGER_006a6fb4)
                                                                    (0,puStack_698);
                                                  if (iVar4 != 0) {
                                                    iVar7 = (*(code *)PTR_OCSP_cert_id_new_006a7e2c)
                                                                      (iStack_6b0,uVar9,uVar10,iVar4
                                                                      );
                                                    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar4)
                                                    ;
                                                    goto joined_r0x0047496c;
                                                  }
                                                  (*(code *)PTR_BIO_printf_006a6e38)
                                                            (*(undefined4 *)puVar16,
                                                             "Error converting serial number %s\n",
                                                             puStack_698);
                                                  goto LAB_00473514;
                                                  }
                                                }
                                                (*(code *)PTR_BIO_printf_006a6e38)
                                                          (*(undefined4 *)puVar16,
                                                           "Error Creating OCSP request\n");
                                                goto LAB_00473514;
                                              }
                                              if (ppuVar18[1] == (undefined *)0x0)
                                              goto LAB_00472528;
                                              (*(code *)PTR_X509_free_006a6e90)(iStack_694);
                                              iStack_694 = load_cert(*(undefined4 *)puVar16,
                                                                     ppuVar18[1],3,0,0,pcStack_69c);
                                              if (iStack_694 == 0) goto LAB_00473514;
                                              bVar1 = false;
                                              ppuVar18 = ppuVar18 + 1;
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
LAB_004723ac:
    puVar27 = puStack_6b8;
    if (!bVar1) {
      pcVar25 = ppuVar18[1];
      if ((pcVar25 == (char *)0x0) ||
         (puVar21 = puVar20, pcVar15 = (char *)ppuVar18, *pcVar25 != '-')) goto LAB_004725b0;
LAB_004723cc:
      ppuVar18 = (undefined **)((int)pcVar15 + 4);
      iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,iVar2 + 0x2514);
      if (iVar4 == 0) {
        puVar20 = *(undefined **)((int)pcVar15 + 8);
        if (puVar20 != (undefined *)0x0) {
          bVar1 = false;
          ppuVar18 = (undefined **)((int)pcVar15 + 8);
          goto LAB_004723ac;
        }
      }
      else {
        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,pcVar23 + -0x475c);
        puVar20 = puVar21;
        if (iVar4 == 0) {
          if (*(undefined **)((int)pcVar15 + 8) == (undefined *)0x0) goto LAB_00472528;
          ppuVar26 = (undefined **)((int)pcVar15 + 8);
          iStack_638 = (*(code *)PTR_strtol_006a9958)(*(undefined **)((int)pcVar15 + 8),0,10);
          if (iStack_638 < 0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar16,"Illegal timeout value %s\n",
                       *(undefined **)((int)pcVar15 + 8));
            bVar1 = true;
            ppuVar18 = ppuVar26;
          }
          else {
LAB_00472424:
            bVar1 = false;
            ppuVar18 = ppuVar26;
          }
          goto LAB_004723ac;
        }
        iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,puVar24);
        if (iVar4 == 0) {
          if (puStack_6c4 != (undefined *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_6c4);
          }
          if (puStack_6c0 != (undefined *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_6c0);
          }
          if (puVar28 != (undefined *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)(puVar28);
          }
          if (*(undefined **)((int)pcVar15 + 8) != (undefined *)0x0) {
            iVar4 = (*(code *)PTR_OCSP_parse_url_006a7764)
                              (*(undefined **)((int)pcVar15 + 8),&puStack_5fc,&puStack_5f8,
                               &puStack_5f4,&uStack_5f0);
            bVar1 = iVar4 == 0;
            if (bVar1) {
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar16,"Error parsing URL\n");
            }
            puStack_6c4 = puStack_5fc;
            puStack_6c0 = puStack_5f8;
            ppuVar18 = (undefined **)((int)pcVar15 + 8);
            puVar28 = puStack_5f4;
            goto LAB_004723ac;
          }
        }
        else {
          iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,pcStack_6c8 + -0x2d0c);
          if (iVar4 == 0) {
            if (*(undefined **)((int)pcVar15 + 8) != (undefined *)0x0) {
              bVar1 = false;
              ppuVar18 = (undefined **)((int)pcVar15 + 8);
              puStack_5fc = *(undefined **)((int)pcVar15 + 8);
              goto LAB_004723ac;
            }
          }
          else {
            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-port");
            if (iVar4 == 0) {
              if (*(undefined **)((int)pcVar15 + 8) == (undefined *)0x0) goto LAB_00472528;
              bVar1 = false;
              ppuVar18 = (undefined **)((int)pcVar15 + 8);
              puStack_5f8 = *(undefined **)((int)pcVar15 + 8);
              goto LAB_004723ac;
            }
            iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-header");
            if (iVar4 != 0) {
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-ignore_err");
              if (iVar4 == 0) {
                iStack_63c = 1;
                bVar1 = false;
                goto LAB_004723ac;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-noverify");
              if (iVar4 == 0) {
                bVar1 = false;
                iStack_628 = 1;
                goto LAB_004723ac;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-nonce");
              if (iVar4 == 0) {
                bVar1 = false;
                iStack_674 = 2;
                goto LAB_004723ac;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_nonce");
              if (iVar4 == 0) {
                iStack_674 = 0;
                bVar1 = false;
                goto LAB_004723ac;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-resp_no_certs");
              if (iVar4 == 0) {
                uStack_644 = uStack_644 | 1;
                bVar1 = false;
                goto LAB_004723ac;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-resp_key_id");
              if (iVar4 == 0) {
                uStack_644 = uStack_644 | 0x400;
                bVar1 = false;
                goto LAB_004723ac;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_certs");
              if (iVar4 == 0) {
                bVar1 = false;
                uStack_658 = 1;
                goto LAB_004723ac;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_signature_verify");
              if (iVar4 == 0) {
                uStack_640 = uStack_640 | 4;
                bVar1 = false;
                goto LAB_004723ac;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_cert_verify");
              if (iVar4 == 0) {
                uStack_640 = uStack_640 | 0x10;
                bVar1 = false;
                goto LAB_004723ac;
              }
              iVar4 = (*(code *)PTR_strcmp_006a9b18)(pcVar25,"-no_chain");
              if (iVar4 == 0) {
                uStack_640 = uStack_640 | 8;
                bVar1 = false;
                goto LAB_004723ac;
              }
              goto LAB_00474214;
            }
            if ((*(undefined **)((int)pcVar15 + 8) != (undefined *)0x0) &&
               (*(undefined **)((int)pcVar15 + 0xc) != (undefined *)0x0)) {
              iVar4 = (*(code *)PTR_X509V3_add_value_006a7db4)
                                (*(undefined **)((int)pcVar15 + 8),
                                 *(undefined **)((int)pcVar15 + 0xc),&uStack_5ec);
              if (iVar4 == 0) goto LAB_00473514;
              bVar1 = false;
              ppuVar18 = (undefined **)((int)pcVar15 + 0xc);
              goto LAB_004723ac;
            }
          }
        }
      }
LAB_00472528:
      bVar1 = true;
      puVar20 = puVar21;
      goto LAB_004723ac;
    }
    bVar1 = true;
LAB_004725b0:
    if (((((iStack_5e8 == 0) && (puStack_6ac == (undefined *)0x0)) &&
         (puStack_630 == (undefined *)0x0)) &&
        ((puStack_5f8 == (undefined *)0x0 || (puStack_668 == (undefined *)0x0)))) || (bVar1)) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar16,"OCSP utility\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar16,"Usage ocsp [options]\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar16,"where options are\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-out file            output filename\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-issuer file         issuer certificate\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-cert file           certificate to check\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-serial n            serial number to check\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-signer file         certificate to sign OCSP request with\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-signkey file        private key to sign OCSP request with\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-sign_other file     additional certificates to include in signed request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-no_certs            don\'t include any certificates in signed request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-req_text            print text form of request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-resp_text           print text form of response\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-text                print text form of request and response\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-reqout file         write DER encoded OCSP request to \"file\"\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-respout file        write DER encoded OCSP reponse to \"file\"\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-reqin file          read DER encoded OCSP request from \"file\"\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-respin file         read DER encoded OCSP reponse from \"file\"\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-nonce               add OCSP nonce to request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-no_nonce            don\'t add OCSP nonce to request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-url URL             OCSP responder URL\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-host host:n         send OCSP request to host on port n\n"
                );
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-path                path to use in OCSP request\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-CApath dir          trusted certificates directory\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-CAfile file         trusted certificates file\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-no_alt_chains       only ever use the first certificate chain found\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-VAfile file         validator certificates file\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-validity_period n   maximum validity discrepancy in seconds\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-status_age n        maximum status age in seconds\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-noverify            don\'t verify response at all\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-verify_other file   additional certificates to search for signer\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-trust_other         don\'t verify additional certificates\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-no_intern           don\'t search certificates contained in response for signer\n"
                );
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-no_signature_verify don\'t check signature on response\n")
      ;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-no_cert_verify      don\'t check signing certificate\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-no_chain            don\'t chain verify response\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-no_cert_checks      don\'t do additional checks on signing certificate\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-port num            port to run responder on\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-index file          certificate status index file\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-CA file             CA certificate\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-rsigner file        responder certificate to sign responses with\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-rkey file           responder key to sign responses with\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-rother file         other certificates to include in response\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-resp_no_certs       don\'t include any certificates in response\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-nmin n              number of minutes before next update\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-ndays n             number of days before next update\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-resp_key_id         identify reponse by signing certificate key ID\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-nrequest n          number of requests to accept (default unlimited)\n");
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,"-<dgst alg>          use specified digest in the request\n"
                );
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar16,
                 "-timeout n           timeout connection to OCSP responder after n seconds\n");
LAB_00473514:
      ppuVar18 = (undefined **)0x0;
      iStack_6b0 = 0;
    }
    else {
      if (puVar20 == (undefined *)0x0) {
        iStack_6b0 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
      }
      else {
        iStack_6b0 = (*(code *)PTR_BIO_new_file_006a6eac)(puVar20,"w");
      }
      puVar21 = puStack_5f8;
      if (iStack_6b0 == 0) {
        ppuVar18 = (undefined **)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar16,"Error opening output file\n");
      }
      else {
        if (iStack_5e8 != 0) {
LAB_004725f4:
          puStack_6b8 = (undefined *)0x0;
          if (puStack_6bc == (undefined *)0x0) {
            pcVar23 = (char *)0x0;
            iStack_610 = 0;
            puStack_6a8 = (undefined *)0x0;
            puStack_6ac = (undefined *)0x0;
          }
          else {
LAB_00472600:
            puVar21 = PTR_bio_err_006a6e3c;
            puVar24 = puStack_6bc;
            if (puVar27 != (undefined *)0x0) {
              puVar24 = puVar27;
            }
            puStack_6ac = (undefined *)
                          load_cert(*(undefined4 *)puVar16,puStack_6bc,3,0,0,"responder certificate"
                                   );
            if (puStack_6ac == (undefined *)0x0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar21,"Error loading responder certificate\n");
              pcVar23 = (char *)0x0;
LAB_004739a0:
              puStack_698 = (undefined *)0x0;
              ppuVar18 = (undefined **)0x0;
              puVar24 = (undefined *)0x1;
              puStack_6bc = (undefined *)0x0;
              puVar20 = (undefined *)0x0;
              puStack_6a8 = (undefined *)0x0;
              pcVar25 = (char *)0x0;
              pcStack_69c = (char *)0x0;
              pcStack_6c8 = (char *)0x0;
              iVar2 = 0;
              goto LAB_00472078;
            }
            pcVar23 = (char *)load_cert(*(undefined4 *)puVar21,puStack_6a8,3,0,0,"CA certificate");
            if (pcStack_6b4 == (char *)0x0) {
              iStack_610 = 0;
            }
            else {
              iStack_610 = load_certs(*(undefined4 *)puVar21,pcStack_6b4,3,0,0,
                                      "responder other certificates");
              if (iStack_610 == 0) goto LAB_004739a0;
            }
            puStack_6a8 = (undefined *)
                          load_key(*(undefined4 *)puVar16,puVar24,3,0,0,0,"responder private key");
            if (puStack_6a8 == (undefined *)0x0) {
              ppuVar18 = (undefined **)0x0;
              puStack_6bc = (undefined *)0x0;
              puStack_698 = (undefined *)0x0;
              pcStack_69c = (char *)0x0;
              puVar24 = (undefined *)0x1;
              pcStack_6c8 = (char *)0x0;
              puVar20 = (undefined *)0x0;
              pcVar25 = (char *)0x0;
              iVar2 = 0;
              goto LAB_00472078;
            }
            if (puStack_6b8 != (undefined *)0x0) {
LAB_004726f0:
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar16,"Waiting for OCSP client connections...\n");
            }
          }
          puStack_6bc = (undefined *)0x0;
          pcStack_69c = (char *)0x0;
          pcStack_6c8 = (char *)0x0;
          puStack_698 = (undefined *)0x0;
          iVar4 = (int)puStack_6a4 * 0x3c;
          ppuVar18 = (undefined **)0x0;
LAB_00472770:
          do {
            if (puStack_6b8 != (undefined *)0x0) {
              iVar2 = do_responder_isra_0(&iStack_5e8,&iStack_5e4,puStack_6b8);
              if (iVar2 != 0) {
                if (iStack_5e8 != 0) goto LAB_004727a0;
                ppuVar18 = (undefined **)(*(code *)PTR_OCSP_response_create_006a7db8)(1,0);
                puVar5 = auStack_5b0;
                puVar14 = (undefined4 *)
                          "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
                ;
                do {
                  puVar13 = puVar14 + 4;
                  puVar12 = puVar5 + 4;
                  uVar17 = puVar14[1];
                  uVar10 = puVar14[2];
                  uVar9 = puVar14[3];
                  *puVar5 = *puVar14;
                  puVar5[1] = uVar17;
                  puVar5[2] = uVar10;
                  puVar5[3] = uVar9;
                  puVar5 = puVar12;
                  puVar14 = puVar13;
                } while (puVar13 != (undefined4 *)0x64551c);
                *(char *)puVar12 = s_HTTP_1_0_200_OK_Content_type__ap_006454cc[80];
                if (iStack_5e4 == 0) goto LAB_00472db0;
LAB_00472ca0:
                iVar2 = iStack_5e4;
                uVar9 = (*(code *)PTR_i2d_OCSP_RESPONSE_006a7794)(ppuVar18,0);
                (*(code *)PTR_BIO_printf_006a6e38)(iVar2,auStack_5b0,uVar9);
                (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_OCSP_RESPONSE_006a7794,iVar2,ppuVar18);
                (*(code *)PTR_BIO_ctrl_006a6e18)(iVar2,0xb,0,0);
                goto LAB_00472db0;
              }
LAB_00473760:
              puVar24 = (undefined *)0x1;
              puVar20 = (undefined *)0x0;
              pcVar25 = (char *)0x0;
              iVar2 = 0;
              goto LAB_00472078;
            }
            if (iStack_5e8 == 0) {
              if (((puStack_670 != (undefined *)0x0) || (puStack_66c != (undefined *)0x0)) ||
                 ((puStack_5fc != (undefined *)0x0 ||
                  ((iStack_674 != 0 || (puStack_668 != (undefined *)0x0)))))) {
                pcVar15 = "Need an OCSP request for this operation!\n";
                uVar9 = *(undefined4 *)puVar16;
LAB_00473718:
                puVar24 = (undefined *)0x1;
                (*(code *)PTR_BIO_printf_006a6e38)(uVar9,pcVar15);
                puVar20 = (undefined *)0x0;
                pcVar25 = (char *)0x0;
                iVar2 = 0;
                goto LAB_00472078;
              }
LAB_00472d64:
              if (puStack_698 == (undefined *)0x0) {
                if (puStack_5fc != (undefined *)0x0) {
                  ppuVar18 = (undefined **)
                             process_responder(*(undefined4 *)puVar16,iStack_5e8,puStack_5fc,
                                               puStack_5f4,puStack_5f8,uStack_5f0,uStack_5ec,
                                               iStack_638);
                  if (ppuVar18 == (undefined **)0x0) goto LAB_00473760;
                  goto LAB_00472db0;
                }
                if (puStack_630 != (undefined *)0x0) {
                  iVar2 = (*(code *)PTR_BIO_new_file_006a6eac)(puStack_630,&DAT_00633e40);
                  if (iVar2 != 0) {
                    ppuVar18 = (undefined **)
                               (*(code *)PTR_ASN1_d2i_bio_006a71c4)
                                         (PTR_OCSP_RESPONSE_new_006a7e00,
                                          PTR_d2i_OCSP_RESPONSE_006a793c,iVar2,0);
                    (*(code *)PTR_BIO_free_006a6e70)(iVar2);
                    if (ppuVar18 == (undefined **)0x0) {
                      pcVar15 = "Error reading OCSP response\n";
                      uVar9 = *(undefined4 *)puVar16;
                      goto LAB_00473718;
                    }
                    goto LAB_00472db0;
                  }
                  puVar24 = (undefined *)0x1;
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar16,"Error Opening OCSP response file\n");
                  puVar20 = (undefined *)0x0;
                  pcVar25 = (char *)0x0;
                  goto LAB_00472078;
                }
                break;
              }
            }
            else {
LAB_004727a0:
              if (iStack_674 != 0) {
                (*(code *)PTR_OCSP_request_add1_nonce_006a7dbc)(iStack_5e8,0,0xffffffff);
              }
              puVar21 = PTR_bio_err_006a6e3c;
              if (puStack_670 != (undefined *)0x0) {
                pcStack_6c8 = (char *)load_cert(*(undefined4 *)puVar16,puStack_670,3,0,0,
                                                "signer certificate");
                if (puStack_67c == (undefined *)0x0) {
                  puStack_67c = puStack_670;
                }
                if (pcStack_6c8 == (char *)0x0) {
                  pcVar15 = "Error loading signer certificate\n";
                  uVar9 = *(undefined4 *)puVar21;
                }
                else {
                  if (((puStack_660 != (undefined *)0x0) &&
                      (puStack_6bc = (undefined *)
                                     load_certs(*(undefined4 *)puVar21,puStack_660,3,0,0,
                                                "signer certificates"),
                      puStack_6bc == (undefined *)0x0)) ||
                     (pcStack_69c = (char *)load_key(*(undefined4 *)puVar16,puStack_67c,3,0,0,0,
                                                     "signer private key"),
                     pcStack_69c == (char *)0x0)) goto LAB_00473760;
                  iVar2 = (*(code *)PTR_OCSP_request_sign_006a7dc0)
                                    (iStack_5e8,pcStack_6c8,pcStack_69c,0,puStack_6bc,uStack_658);
                  if (iVar2 != 0) goto LAB_00472898;
                  pcVar15 = "Error signing OCSP request\n";
                  uVar9 = *(undefined4 *)PTR_bio_err_006a6e3c;
                }
                goto LAB_00473718;
              }
LAB_00472898:
              if ((iStack_65c != 0) && (iStack_5e8 != 0)) {
                (*(code *)PTR_OCSP_REQUEST_print_006a7dc4)(iStack_6b0,iStack_5e8,0);
              }
              if (puStack_66c != (undefined *)0x0) {
                iVar2 = (*(code *)PTR_BIO_new_file_006a6eac)(puStack_66c,&DAT_00632420);
                if (iVar2 != 0) {
                  (*(code *)PTR_ASN1_i2d_bio_006a7198)
                            (PTR_i2d_OCSP_REQUEST_006a7dc8,iVar2,iStack_5e8);
                  (*(code *)PTR_BIO_free_006a6e70)(iVar2);
                  goto LAB_00472910;
                }
                uVar9 = *(undefined4 *)puVar16;
                puVar21 = puStack_66c;
LAB_00473af0:
                puVar24 = (undefined *)0x1;
                puVar20 = (undefined *)0x0;
                (*(code *)PTR_BIO_printf_006a6e38)(uVar9,"Error opening file %s\n",puVar21);
                pcVar25 = (char *)0x0;
                goto LAB_00472078;
              }
LAB_00472910:
              if (puStack_668 == (undefined *)0x0) goto LAB_00472d64;
              if (((puStack_6a8 == (undefined *)0x0) || (puStack_6ac == (undefined *)0x0)) ||
                 (pcVar23 == (char *)0x0)) {
                pcVar15 = "Need a responder certificate, key and CA for this operation!\n";
                uVar9 = *(undefined4 *)puVar16;
                goto LAB_00473718;
              }
              if (puStack_698 != (undefined *)0x0) goto LAB_0047293c;
              puStack_698 = (undefined *)load_index(puStack_668,0);
              if (puStack_698 == (undefined *)0x0) {
                puVar24 = (undefined *)0x1;
                puVar20 = (undefined *)0x0;
                pcVar25 = (char *)0x0;
                iVar2 = 0;
                goto LAB_00472078;
              }
              iVar2 = index_index(puStack_698);
              if (iVar2 == 0) goto LAB_00473760;
            }
LAB_0047293c:
            iVar2 = iStack_5e8;
            iVar7 = (*(code *)PTR_OCSP_request_onereq_count_006a7dcc)(iStack_5e8);
            if (iVar7 < 1) {
              iVar22 = 0;
              ppuVar18 = (undefined **)(*(code *)PTR_OCSP_response_create_006a7db8)(1,0);
              pcStack_6b4 = (char *)0x0;
              pcStack_6a0 = (char *)0x0;
              puStack_6a4 = (undefined *)0x0;
            }
            else {
              pcStack_6b4 = (char *)(*(code *)PTR_OCSP_BASICRESP_new_006a7dd0)();
              puStack_6a4 = (undefined *)(*(code *)PTR_X509_gmtime_adj_006a6f8c)(0,0);
              if (iStack_64c == -1) {
                pcStack_6a0 = (char *)0x0;
              }
              else {
                pcStack_6a0 = (char *)(*(code *)PTR_X509_time_adj_ex_006a6f90)(0,iStack_64c,iVar4,0)
                ;
              }
              iVar22 = 0;
              iVar19 = 0;
              do {
                while( true ) {
                  uVar9 = (*(code *)PTR_OCSP_request_onereq_get0_006a7ddc)(iVar2,iVar19);
                  uVar9 = (*(code *)PTR_OCSP_onereq_get0_id_006a7de0)(uVar9);
                  (*(code *)PTR_OCSP_id_get0_info_006a7dd4)(0,&iStack_5dc,0,0,uVar9);
                  uVar10 = (*(code *)PTR_OBJ_obj2nid_006a712c)(iStack_5dc);
                  uVar10 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar10);
                  iVar11 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar10);
                  if (iVar11 == 0) {
                    ppuVar18 = (undefined **)(*(code *)PTR_OCSP_response_create_006a7db8)(2,0);
                    goto LAB_00472c04;
                  }
                  if (iVar22 != 0) {
                    (*(code *)PTR_OCSP_CERTID_free_006a7770)(iVar22);
                  }
                  iVar22 = (*(code *)PTR_OCSP_cert_to_id_006a7780)(iVar11,0,pcVar23);
                  iVar11 = (*(code *)PTR_OCSP_id_issuer_cmp_006a7de4)(iVar22,uVar9);
                  if (iVar11 == 0) break;
LAB_00472b70:
                  uVar10 = 2;
LAB_00472b7c:
                  iVar19 = iVar19 + 1;
                  (*(code *)PTR_OCSP_basic_add1_status_006a7de8)
                            (pcStack_6b4,uVar9,uVar10,0,0,puStack_6a4,pcStack_6a0);
                  if (iVar7 == iVar19) goto LAB_00472ba8;
                }
                (*(code *)PTR_OCSP_id_get0_info_006a7dd4)(0,0,0,&uStack_5e0,uVar9);
                uStack_5c8 = 0;
                uStack_5c4 = 0;
                uStack_5c0 = 0;
                uStack_5bc = 0;
                uStack_5b8 = 0;
                uStack_5b4 = 0;
                iVar11 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(uStack_5e0,0);
                if (iVar11 == 0) {
                  (*(code *)PTR_OpenSSLDie_006a7c5c)("ocsp.c",0x445,&DAT_0064534c);
                }
                if (*(int *)(iVar11 + 4) == 0) {
                  uVar10 = (*(code *)PTR_BUF_strdup_006a6fdc)("00");
                }
                else {
                  uVar10 = (*(code *)PTR_BN_bn2hex_006a7018)(iVar11);
                }
                uStack_5bc = uVar10;
                (*(code *)PTR_BN_free_006a701c)(iVar11);
                ppcVar8 = (char **)(*(code *)PTR_TXT_DB_get_by_index_006a7020)
                                             (*(undefined4 *)((int)puStack_698 + 4),3,&uStack_5c8);
                (*(code *)PTR_CRYPTO_free_006a6e88)(uVar10);
                if (ppcVar8 == (char **)0x0) goto LAB_00472b70;
                if (**ppcVar8 == 'V') {
                  uVar10 = 0;
                  goto LAB_00472b7c;
                }
                if (**ppcVar8 == 'R') {
                  iStack_5d8 = 0;
                  uStack_5d4 = 0;
                  iStack_5d0 = 0;
                  iStack_5cc = -1;
                  (*(code *)PTR_unpack_revinfo_006a7dd8)
                            (&uStack_5d4,&iStack_5cc,&iStack_5d8,&iStack_5d0,ppcVar8[2]);
                  uVar9 = (*(code *)PTR_OCSP_basic_add1_status_006a7de8)
                                    (pcStack_6b4,uVar9,1,iStack_5cc,uStack_5d4,puStack_6a4,
                                     pcStack_6a0);
                  if (iStack_5d0 == 0) {
                    if (iStack_5d8 != 0) {
                      (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a7df8)
                                (uVar9,0x1ae,iStack_5d8,0,0);
                    }
                  }
                  else {
                    (*(code *)PTR_OCSP_SINGLERESP_add1_ext_i2d_006a7df8)(uVar9,0x8e,iStack_5d0,0,0);
                  }
                  (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iStack_5d8);
                  (*(code *)PTR_ASN1_TIME_free_006a7050)(uStack_5d4);
                  (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a7038)(iStack_5d0);
                }
                iVar19 = iVar19 + 1;
              } while (iVar7 != iVar19);
LAB_00472ba8:
              (*(code *)PTR_OCSP_copy_nonce_006a7dec)(pcStack_6b4,iVar2);
              (*(code *)PTR_OCSP_basic_sign_006a7df0)
                        (pcStack_6b4,puStack_6ac,puStack_6a8,0,iStack_610,uStack_644);
              ppuVar18 = (undefined **)(*(code *)PTR_OCSP_response_create_006a7db8)(0,pcStack_6b4);
            }
LAB_00472c04:
            (*(code *)PTR_ASN1_TIME_free_006a7050)(puStack_6a4);
            (*(code *)PTR_ASN1_TIME_free_006a7050)(pcStack_6a0);
            (*(code *)PTR_OCSP_CERTID_free_006a7770)(iVar22);
            (*(code *)PTR_OCSP_BASICRESP_free_006a7db0)(pcStack_6b4);
            if (iStack_5e4 != 0) {
              puVar5 = (undefined4 *)
                       "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
              ;
              puVar14 = auStack_5b0;
              do {
                puVar12 = puVar5 + 4;
                puVar13 = puVar14 + 4;
                uVar17 = puVar5[1];
                uVar10 = puVar5[2];
                uVar9 = puVar5[3];
                *puVar14 = *puVar5;
                puVar14[1] = uVar17;
                puVar14[2] = uVar10;
                puVar14[3] = uVar9;
                puVar5 = puVar12;
                puVar14 = puVar13;
              } while (puVar12 != (undefined4 *)0x64551c);
              *(char *)puVar13 = s_HTTP_1_0_200_OK_Content_type__ap_006454cc[80];
              goto LAB_00472ca0;
            }
LAB_00472db0:
            if (puStack_664 != (undefined *)0x0) {
              iVar2 = (*(code *)PTR_BIO_new_file_006a6eac)(puStack_664,&DAT_00632420);
              if (iVar2 == 0) {
                uVar9 = *(undefined4 *)puVar16;
                puVar21 = puStack_664;
                goto LAB_00473af0;
              }
              (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_OCSP_RESPONSE_006a7794,iVar2,ppuVar18);
              (*(code *)PTR_BIO_free_006a6e70)(iVar2);
            }
            iVar2 = (*(code *)PTR_OCSP_response_status_006a7df4)(ppuVar18);
            if (iVar2 == 0) {
              if (iStack_650 != 0) {
                (*(code *)PTR_OCSP_RESPONSE_print_006a7798)(iStack_6b0,ppuVar18,0);
              }
              if (iStack_5e4 == 0) {
                pcVar25 = (char *)setup_verify(*(undefined4 *)puVar16,puStack_61c,puStack_618);
                if (pcVar25 == (char *)0x0) {
                  puVar24 = (undefined *)0x1;
                  puVar20 = (undefined *)0x0;
                  iVar2 = 0;
                  goto LAB_00472078;
                }
                if (puStack_62c == (undefined *)0x0) {
                  puVar20 = (undefined *)0x0;
                }
                else {
                  puVar20 = (undefined *)
                            load_certs(*(undefined4 *)PTR_bio_err_006a6e3c,puStack_62c,3,0,0,
                                       "validator certificate");
                  if (puVar20 == (undefined *)0x0) {
                    puVar24 = (undefined *)0x1;
                    iVar2 = 0;
                    goto LAB_00472078;
                  }
                }
                iVar2 = (*(code *)PTR_OCSP_response_get1_basic_006a7e08)(ppuVar18);
                if (iVar2 == 0) {
                  puVar24 = (undefined *)0x1;
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar16,"Error parsing response\n");
                  goto LAB_00472078;
                }
                if (iStack_628 == 0) {
                  if ((iStack_5e8 != 0) &&
                     (iVar4 = (*(code *)PTR_OCSP_check_nonce_006a7e0c)(iStack_5e8,iVar2), iVar4 < 1)
                     ) {
                    if (iVar4 != -1) {
                      puVar24 = (undefined *)0x1;
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar16,"Nonce Verify error\n");
                      goto LAB_00472078;
                    }
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar16,"WARNING: no nonce in response\n");
                  }
                  iVar4 = (*(code *)PTR_OCSP_basic_verify_006a7e10)
                                    (iVar2,puVar20,pcVar25,uStack_640);
                  if (iVar4 < 0) {
                    iVar4 = (*(code *)PTR_OCSP_basic_verify_006a7e10)(iVar2,0,pcVar25,0);
                  }
                  if (iVar4 < 1) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar16,"Response Verify Failure\n");
                    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar16);
                  }
                  else {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)puVar16,"Response verify OK\n");
                  }
                }
                if (((iStack_5e8 == 0) ||
                    (iVar4 = (*(code *)PTR_sk_num_006a6e2c)(uStack_688), iVar4 == 0)) ||
                   (iVar4 = (*(code *)PTR_sk_num_006a6e2c)(uStack_690), iVar4 == 0)) {
                  puVar24 = (undefined *)0x0;
                  goto LAB_00472078;
                }
                iVar4 = 0;
                pcStack_6b4 = "-check_ss_sig";
                puStack_6a4 = &DAT_00631e78;
                pcStack_6a0 = "%s\n";
                goto LAB_00473ce0;
              }
              iStack_678 = iStack_678 - (uint)(0 < iStack_678);
              if (iStack_678 == 0) goto LAB_00473760;
              (*(code *)PTR_BIO_free_all_006a6e74)();
              iStack_5e4 = 0;
              (*(code *)PTR_OCSP_REQUEST_free_006a7774)(iStack_5e8);
              iStack_5e8 = 0;
              (*(code *)PTR_OCSP_RESPONSE_free_006a7778)(ppuVar18);
              ppuVar18 = (undefined **)0x0;
              goto LAB_00472770;
            }
            uVar9 = (*(code *)PTR_OCSP_response_status_str_006a7dfc)(iVar2);
            (*(code *)PTR_BIO_printf_006a6e38)(iStack_6b0,"Responder Error: %s (%d)\n",uVar9,iVar2);
          } while (iStack_63c != 0);
          puVar24 = (undefined *)0x0;
          puVar20 = (undefined *)0x0;
          pcVar25 = (char *)0x0;
          iVar2 = 0;
          goto LAB_00472078;
        }
        if (iStack_674 != 2) {
          iStack_674 = 0;
        }
        if (puStack_6ac == (undefined *)0x0) {
          if (puStack_5f8 == (undefined *)0x0) goto LAB_004725f4;
          uVar9 = (*(code *)PTR_BIO_f_buffer_006a7854)();
          iVar2 = (*(code *)PTR_BIO_new_006a6ea4)(uVar9);
          if (iVar2 == 0) {
            puStack_6b8 = (undefined *)0x0;
          }
          else {
            puStack_6b8 = (undefined *)(*(code *)PTR_BIO_new_accept_006a7e04)(puVar21);
            if (puStack_6b8 != (undefined *)0x0) {
              (*(code *)PTR_BIO_ctrl_006a6e18)(puStack_6b8,0x76,2,iVar2);
              iVar2 = (*(code *)PTR_BIO_ctrl_006a6e18)(puStack_6b8,0x65,0,0);
              if (0 < iVar2) {
                pcVar23 = (char *)0x0;
                if (puStack_6bc != (undefined *)0x0) goto LAB_00472600;
                iStack_610 = 0;
                puStack_6a8 = (undefined *)0x0;
                puStack_6ac = (undefined *)0x0;
                goto LAB_004726f0;
              }
              iVar2 = 0;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar16,"Error setting up accept BIO\n");
              (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar16);
            }
          }
          ppuVar18 = (undefined **)0x0;
          (*(code *)PTR_BIO_free_all_006a6e74)(puStack_6b8);
          (*(code *)PTR_BIO_free_006a6e70)(iVar2);
        }
        else {
          ppuVar18 = (undefined **)(*(code *)PTR_BIO_new_file_006a6eac)(puStack_6ac,&DAT_00633e40);
          if (ppuVar18 == (undefined **)0x0) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar16,"Error Opening OCSP request file\n");
          }
          else {
            iStack_5e8 = (*(code *)PTR_ASN1_d2i_bio_006a71c4)
                                   (PTR_OCSP_REQUEST_new_006a777c,PTR_d2i_OCSP_REQUEST_006a7d90,
                                    ppuVar18,0);
            (*(code *)PTR_BIO_free_006a6e70)(ppuVar18);
            if (iStack_5e8 != 0) goto LAB_004725f4;
            ppuVar18 = (undefined **)0x0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar16,"Error reading OCSP request\n");
          }
        }
      }
    }
    puStack_6bc = (undefined *)0x0;
    puStack_698 = (undefined *)0x0;
    pcVar25 = (char *)0x0;
    pcVar23 = (char *)0x0;
    puVar20 = (undefined *)0x0;
    puVar24 = (undefined *)0x1;
    puStack_6b8 = (undefined *)0x0;
    iVar2 = 0;
    puStack_6a8 = (undefined *)0x0;
    pcStack_69c = (char *)0x0;
    puStack_6ac = (undefined *)0x0;
    pcStack_6c8 = (char *)0x0;
  } while( true );
LAB_00471d38:
  do {
    pcVar15 = (char *)ppuStack_550;
    iVar4 = (**(code **)(puStack_518 + -0x703c))(unaff_s7);
  } while (iVar4 == -1);
  pcVar29 = *(code **)(puStack_518 + -0x7038);
LAB_00471cd4:
  (*pcVar29)(ppuStack_550);
  puStack_558 = puStack_500;
  if (puStack_500 == (undefined *)0x0) {
    puVar5 = *(undefined4 **)(puStack_518 + -0x7fa4);
LAB_00471eb8:
    pcVar15 = "Error querying OCSP responder\n";
    (**(code **)(puStack_518 + -0x7fa8))(*puVar5);
    puStack_558 = (undefined *)0x0;
  }
LAB_00471a9c:
  if (iVar2 != 0) goto LAB_00471aa4;
  goto LAB_00471ab4;
LAB_00473ce0:
  iVar7 = (*(code *)PTR_sk_num_006a6e2c)(uStack_690);
  if (iVar4 < iVar7) {
    iStack_678 = (*(code *)PTR_sk_value_006a6e24)(uStack_690,iVar4);
    uVar9 = (*(code *)PTR_sk_value_006a6e24)(uStack_688,iVar4);
    (*(code *)PTR_BIO_printf_006a6e38)(iStack_6b0,&DAT_00631e78,uVar9);
    iVar7 = (*(code *)PTR_OCSP_resp_find_status_006a7e14)
                      (iVar2,iStack_678,&iStack_5dc,&iStack_5d8,&uStack_5d4,&iStack_5d0,&iStack_5cc)
    ;
    if (iVar7 == 0) {
      (*(code *)PTR_BIO_puts_006a6f58)(iStack_6b0,"ERROR: No Status found.\n");
LAB_00473d90:
      iVar4 = iVar4 + 1;
    }
    else {
      iVar7 = (*(code *)PTR_OCSP_check_validity_006a7e18)
                        (iStack_5d0,iStack_5cc,iStack_624,iStack_620);
      if (iVar7 == 0) {
        (*(code *)PTR_BIO_puts_006a6f58)(iStack_6b0,"WARNING: Status times invalid.\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(iStack_6b0);
      }
      uVar9 = (*(code *)PTR_OCSP_cert_status_str_006a7e1c)(iStack_5dc);
      (*(code *)PTR_BIO_printf_006a6e38)(iStack_6b0,"%s\n",uVar9);
      (*(code *)PTR_BIO_puts_006a6f58)(iStack_6b0,"\tThis Update: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(iStack_6b0,iStack_5d0);
      (*(code *)PTR_BIO_puts_006a6f58)(iStack_6b0,"\n");
      if (iStack_5cc != 0) {
        (*(code *)PTR_BIO_puts_006a6f58)(iStack_6b0,"\tNext Update: ");
        (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(iStack_6b0,iStack_5cc);
        (*(code *)PTR_BIO_puts_006a6f58)(iStack_6b0,"\n");
      }
      if (iStack_5dc != 1) goto LAB_00473d90;
      if (iStack_5d8 != -1) {
        uVar9 = (*(code *)PTR_OCSP_crl_reason_str_006a7e24)();
        (*(code *)PTR_BIO_printf_006a6e38)(iStack_6b0,"\tReason: %s\n",uVar9);
      }
      iVar4 = iVar4 + 1;
      (*(code *)PTR_BIO_puts_006a6f58)(iStack_6b0,"\tRevocation Time: ");
      (*(code *)PTR_ASN1_GENERALIZEDTIME_print_006a7e20)(iStack_6b0,uStack_5d4);
      (*(code *)PTR_BIO_puts_006a6f58)(iStack_6b0,"\n");
    }
    goto LAB_00473ce0;
  }
  puVar24 = (undefined *)0x0;
  puStack_67c = puVar28;
  goto LAB_00472078;
}

