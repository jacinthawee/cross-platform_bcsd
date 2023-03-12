
undefined4 old_entry_print(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined *puVar10;
  undefined4 uVar11;
  char *pcVar12;
  char *pcVar13;
  undefined local_40 [28];
  undefined4 *local_24;
  
  puVar4 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  iVar1 = (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)();
  puVar2 = local_40;
  iVar1 = 0x16 - iVar1;
  puVar3 = puVar2;
  if (0 < iVar1) {
    puVar2 = (undefined *)(*(code *)PTR_memset_006aab00)(puVar2,0x20,iVar1);
    puVar3 = puVar2 + iVar1;
  }
  puVar3[1] = 0;
  *puVar3 = 0x3a;
  (*(code *)PTR_BIO_puts_006a8058)(param_1,puVar2);
  piVar9 = (int *)param_3[1];
  if (piVar9 == (int *)&DAT_00000013) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"PRINTABLE:\'");
  }
  else if (piVar9 == (int *)&DAT_00000014) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"T61STRING:\'");
  }
  else if (piVar9 == (int *)&DAT_00000016) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"IA5STRING:\'");
  }
  else if (piVar9 == (int *)0x1c) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"UNIVERSALSTRING:\'");
  }
  else {
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"ASN.1 %2d:\'");
  }
  pcVar13 = (char *)param_3[2];
  pcVar12 = pcVar13 + *param_3;
  if (0 < *param_3) {
    do {
      while (piVar9 = (int *)(int)*pcVar13, 0x5e < ((uint)(piVar9 + -8) & 0xff)) {
        if ((int)piVar9 < 0) {
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\\0x%02X");
        }
        else {
          piVar9 = piVar9 + 0x10;
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,&DAT_00635c74);
        }
        pcVar13 = pcVar13 + 1;
        if (pcVar13 == pcVar12) goto LAB_0042fa58;
      }
      pcVar13 = pcVar13 + 1;
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%c");
    } while (pcVar13 != pcVar12);
  }
LAB_0042fa58:
  puVar8 = (undefined4 *)0x63ae04;
  (*(code *)PTR_BIO_printf_006a7f38)(param_1);
  if (local_24 == *(undefined4 **)puVar4) {
    return 1;
  }
  puVar7 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = (undefined *)(*(code *)PTR_BUF_strdup_006a80dc)(&_gp);
  puVar2 = (undefined *)(*(code *)PTR_strchr_006aab34)(puVar3,0x2c);
  puVar4 = PTR_strchr_006aab34;
  if (puVar2 == (undefined *)0x0) {
    if (puVar7 != (undefined4 *)0x0) {
      uVar5 = (*(code *)PTR_ASN1_UTCTIME_new_006a8130)();
      puVar4 = PTR_ASN1_UTCTIME_set_string_006a8134;
      *puVar7 = uVar5;
      iVar1 = (*(code *)puVar4)(uVar5,puVar3);
      if (iVar1 == 0) goto LAB_0042fdc4;
    }
    uVar11 = 0;
    iVar1 = 0;
    uVar5 = 0xffffffff;
    goto LAB_0042fdec;
  }
  puVar10 = puVar2 + 1;
  *puVar2 = 0;
  puVar4 = (undefined *)(*(code *)puVar4)(puVar10,0x2c);
  if (puVar4 == (undefined *)0x0) {
    puVar2 = (undefined *)0x0;
  }
  else {
    puVar2 = puVar4 + 1;
    *puVar4 = 0;
  }
  if (puVar7 != (undefined4 *)0x0) {
    uVar5 = (*(code *)PTR_ASN1_UTCTIME_new_006a8130)();
    puVar4 = PTR_ASN1_UTCTIME_set_string_006a8134;
    *puVar7 = uVar5;
    iVar1 = (*(code *)puVar4)(uVar5,puVar3);
    if (iVar1 != 0) goto LAB_0042fbfc;
LAB_0042fdc4:
    pcVar12 = "invalid revocation date %s\n";
    puVar2 = puVar3;
    goto LAB_0042fd40;
  }
LAB_0042fbfc:
  iVar1 = (*(code *)PTR_strcasecmp_006aab24)(puVar10,"unspecified");
  if (iVar1 == 0) {
    uVar5 = 0;
    uVar11 = 0;
    iVar1 = 0;
LAB_0042fdec:
    if (puVar8 != (undefined4 *)0x0) {
      *puVar8 = uVar5;
    }
    puVar4 = PTR_CRYPTO_free_006a7f88;
    if (param_4 == (undefined4 *)0x0) {
      (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(uVar11);
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar3);
      uVar5 = 1;
      if (piVar9 != (int *)0x0) goto LAB_0042fea0;
    }
    else {
      *param_4 = uVar11;
      (*(code *)puVar4)(puVar3);
      uVar5 = 1;
      if (piVar9 != (int *)0x0) {
        return 1;
      }
    }
LAB_0042fe18:
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar1);
  }
  else {
    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(puVar10,"keyCompromise");
    if (iVar1 == 0) {
      uVar5 = 1;
      uVar11 = 0;
      iVar1 = 0;
      goto LAB_0042fdec;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(puVar10,"CACompromise");
    if (iVar1 == 0) {
      uVar5 = 2;
      uVar11 = 0;
      iVar1 = 0;
      goto LAB_0042fdec;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(puVar10,"affiliationChanged");
    if (iVar1 == 0) {
      uVar5 = 3;
      uVar11 = 0;
      iVar1 = 0;
      goto LAB_0042fdec;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(puVar10,"superseded");
    if (iVar1 == 0) {
      uVar5 = 4;
      uVar11 = 0;
      iVar1 = 0;
      goto LAB_0042fdec;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(puVar10,"cessationOfOperation");
    if (iVar1 == 0) {
      uVar5 = 5;
      uVar11 = 0;
      iVar1 = 0;
      goto LAB_0042fdec;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(puVar10,"certificateHold");
    if (iVar1 == 0) {
      uVar5 = 6;
      uVar11 = 0;
      iVar1 = 0;
      goto LAB_0042fdec;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(puVar10,"removeFromCRL");
    if (iVar1 == 0) {
      uVar11 = 0;
      iVar1 = 0;
      uVar5 = 8;
      goto LAB_0042fdec;
    }
    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(puVar10,"holdInstruction");
    if (iVar1 == 0) {
      if (puVar2 != (undefined *)0x0) {
        iVar1 = (*(code *)PTR_OBJ_txt2obj_006a8100)(puVar2,0);
        if (iVar1 == 0) {
          pcVar12 = "invalid object identifier %s\n";
          goto LAB_0042fd40;
        }
        if (piVar9 == (int *)0x0) {
          uVar11 = 0;
          uVar5 = 6;
        }
        else {
          *piVar9 = iVar1;
          uVar11 = 0;
          uVar5 = 6;
        }
        goto LAB_0042fdec;
      }
      pcVar12 = "missing hold instruction\n";
LAB_0042ffe8:
      uVar11 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar12);
    }
    else {
      iVar1 = (*(code *)PTR_strcasecmp_006aab24)(puVar10,"keyTime");
      if (iVar1 == 0) {
        iVar1 = 9;
LAB_0042ff64:
        if (puVar2 == (undefined *)0x0) {
          pcVar12 = "missing compromised time\n";
          goto LAB_0042ffe8;
        }
        uVar11 = (*(code *)PTR_ASN1_GENERALIZEDTIME_new_006a813c)();
        iVar6 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a80fc)(uVar11,puVar2);
        if (iVar6 != 0) {
          uVar5 = 2;
          if (iVar1 == 9) {
            uVar5 = 1;
          }
          iVar1 = 0;
          goto LAB_0042fdec;
        }
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"invalid compromised time %s\n",puVar2);
      }
      else {
        iVar1 = (*(code *)PTR_strcasecmp_006aab24)(puVar10,"CAkeyTime");
        if (iVar1 == 0) {
          iVar1 = 10;
          goto LAB_0042ff64;
        }
        pcVar12 = "invalid reason code %s\n";
        puVar2 = puVar10;
LAB_0042fd40:
        uVar11 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar12,puVar2);
      }
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar3);
    uVar5 = 0;
    if (piVar9 == (int *)0x0) {
      iVar1 = 0;
      goto LAB_0042fe18;
    }
  }
  if (param_4 != (undefined4 *)0x0) {
    return uVar5;
  }
LAB_0042fea0:
  (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(uVar11);
  return uVar5;
}

