
undefined4
unpack_revinfo(undefined4 *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,
              undefined4 param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined *puVar8;
  undefined4 uVar9;
  
  puVar1 = (undefined *)(*(code *)PTR_BUF_strdup_006a80dc)(param_5);
  puVar2 = (undefined *)(*(code *)PTR_strchr_006aab34)(puVar1,0x2c);
  puVar3 = PTR_strchr_006aab34;
  if (puVar2 == (undefined *)0x0) {
    if (param_1 != (undefined4 *)0x0) {
      uVar4 = (*(code *)PTR_ASN1_UTCTIME_new_006a8130)();
      puVar3 = PTR_ASN1_UTCTIME_set_string_006a8134;
      *param_1 = uVar4;
      iVar5 = (*(code *)puVar3)(uVar4,puVar1);
      if (iVar5 == 0) goto LAB_0042fdc4;
    }
    uVar9 = 0;
    iVar5 = 0;
    uVar4 = 0xffffffff;
    goto LAB_0042fdec;
  }
  puVar8 = puVar2 + 1;
  *puVar2 = 0;
  puVar3 = (undefined *)(*(code *)puVar3)(puVar8,0x2c);
  if (puVar3 == (undefined *)0x0) {
    puVar2 = (undefined *)0x0;
  }
  else {
    puVar2 = puVar3 + 1;
    *puVar3 = 0;
  }
  if (param_1 != (undefined4 *)0x0) {
    uVar4 = (*(code *)PTR_ASN1_UTCTIME_new_006a8130)();
    puVar3 = PTR_ASN1_UTCTIME_set_string_006a8134;
    *param_1 = uVar4;
    iVar5 = (*(code *)puVar3)(uVar4,puVar1);
    if (iVar5 != 0) goto LAB_0042fbfc;
LAB_0042fdc4:
    pcVar7 = "invalid revocation date %s\n";
    puVar2 = puVar1;
    goto LAB_0042fd40;
  }
LAB_0042fbfc:
  iVar5 = (*(code *)PTR_strcasecmp_006aab24)(puVar8,"unspecified");
  if (iVar5 == 0) {
    uVar4 = 0;
    uVar9 = 0;
    iVar5 = 0;
LAB_0042fdec:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = uVar4;
    }
    puVar3 = PTR_CRYPTO_free_006a7f88;
    if (param_4 == (undefined4 *)0x0) {
      (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(uVar9);
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar1);
      uVar4 = 1;
      if (param_3 != (int *)0x0) goto LAB_0042fea0;
    }
    else {
      *param_4 = uVar9;
      (*(code *)puVar3)(puVar1);
      uVar4 = 1;
      if (param_3 != (int *)0x0) {
        return 1;
      }
    }
LAB_0042fe18:
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar5);
  }
  else {
    iVar5 = (*(code *)PTR_strcasecmp_006aab24)(puVar8,"keyCompromise");
    if (iVar5 == 0) {
      uVar4 = 1;
      uVar9 = 0;
      iVar5 = 0;
      goto LAB_0042fdec;
    }
    iVar5 = (*(code *)PTR_strcasecmp_006aab24)(puVar8,"CACompromise");
    if (iVar5 == 0) {
      uVar4 = 2;
      uVar9 = 0;
      iVar5 = 0;
      goto LAB_0042fdec;
    }
    iVar5 = (*(code *)PTR_strcasecmp_006aab24)(puVar8,"affiliationChanged");
    if (iVar5 == 0) {
      uVar4 = 3;
      uVar9 = 0;
      iVar5 = 0;
      goto LAB_0042fdec;
    }
    iVar5 = (*(code *)PTR_strcasecmp_006aab24)(puVar8,"superseded");
    if (iVar5 == 0) {
      uVar4 = 4;
      uVar9 = 0;
      iVar5 = 0;
      goto LAB_0042fdec;
    }
    iVar5 = (*(code *)PTR_strcasecmp_006aab24)(puVar8,"cessationOfOperation");
    if (iVar5 == 0) {
      uVar4 = 5;
      uVar9 = 0;
      iVar5 = 0;
      goto LAB_0042fdec;
    }
    iVar5 = (*(code *)PTR_strcasecmp_006aab24)(puVar8,"certificateHold");
    if (iVar5 == 0) {
      uVar4 = 6;
      uVar9 = 0;
      iVar5 = 0;
      goto LAB_0042fdec;
    }
    iVar5 = (*(code *)PTR_strcasecmp_006aab24)(puVar8,"removeFromCRL");
    if (iVar5 == 0) {
      uVar9 = 0;
      iVar5 = 0;
      uVar4 = 8;
      goto LAB_0042fdec;
    }
    iVar5 = (*(code *)PTR_strcasecmp_006aab24)(puVar8,"holdInstruction");
    if (iVar5 == 0) {
      if (puVar2 != (undefined *)0x0) {
        iVar5 = (*(code *)PTR_OBJ_txt2obj_006a8100)(puVar2,0);
        if (iVar5 == 0) {
          pcVar7 = "invalid object identifier %s\n";
          goto LAB_0042fd40;
        }
        if (param_3 == (int *)0x0) {
          uVar9 = 0;
          uVar4 = 6;
        }
        else {
          *param_3 = iVar5;
          uVar9 = 0;
          uVar4 = 6;
        }
        goto LAB_0042fdec;
      }
      pcVar7 = "missing hold instruction\n";
LAB_0042ffe8:
      uVar9 = 0;
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar7);
    }
    else {
      iVar5 = (*(code *)PTR_strcasecmp_006aab24)(puVar8,"keyTime");
      if (iVar5 == 0) {
        iVar5 = 9;
LAB_0042ff64:
        if (puVar2 == (undefined *)0x0) {
          pcVar7 = "missing compromised time\n";
          goto LAB_0042ffe8;
        }
        uVar9 = (*(code *)PTR_ASN1_GENERALIZEDTIME_new_006a813c)();
        iVar6 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a80fc)(uVar9,puVar2);
        if (iVar6 != 0) {
          uVar4 = 2;
          if (iVar5 == 9) {
            uVar4 = 1;
          }
          iVar5 = 0;
          goto LAB_0042fdec;
        }
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,"invalid compromised time %s\n",puVar2);
      }
      else {
        iVar5 = (*(code *)PTR_strcasecmp_006aab24)(puVar8,"CAkeyTime");
        if (iVar5 == 0) {
          iVar5 = 10;
          goto LAB_0042ff64;
        }
        pcVar7 = "invalid reason code %s\n";
        puVar2 = puVar8;
LAB_0042fd40:
        uVar9 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar7,puVar2);
      }
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar1);
    uVar4 = 0;
    if (param_3 == (int *)0x0) {
      iVar5 = 0;
      goto LAB_0042fe18;
    }
  }
  if (param_4 != (undefined4 *)0x0) {
    return uVar4;
  }
LAB_0042fea0:
  (*(code *)PTR_ASN1_GENERALIZEDTIME_free_006a8138)(uVar9);
  return uVar4;
}

