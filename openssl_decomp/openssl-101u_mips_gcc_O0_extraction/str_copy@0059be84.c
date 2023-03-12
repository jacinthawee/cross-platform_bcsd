
undefined4 str_copy(CONF *param_1,char *param_2,int *param_3,char *param_4)

{
  bool bVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  ushort uVar10;
  ushort *puVar5;
  undefined4 uVar6;
  uint uVar7;
  char cVar11;
  undefined *puVar8;
  int iVar9;
  uint uVar12;
  char *pcVar13;
  void *pvVar14;
  undefined4 uVar15;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  
  piVar3 = (int *)(*(code *)PTR_BUF_MEM_new_006a749c)();
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  iVar4 = (*(code *)PTR_strlen_006a9a24)(param_4);
  iVar4 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(piVar3,iVar4 + 1);
  if (iVar4 == 0) {
LAB_0059c05c:
    (*(code *)PTR_BUF_MEM_free_006a7494)(piVar3);
    return 0;
  }
  iVar4 = 0;
  pvVar14 = param_1->meth_data;
  uVar10 = *(ushort *)((int)pvVar14 + ((int)*param_4 & 0xffU) * 2);
  uVar7 = (int)*param_4;
LAB_0059bf2c:
  do {
    while ((uVar10 & 0x40) != 0) {
      cVar11 = param_4[1];
      while( true ) {
        pcVar16 = param_4 + 1;
        uVar12 = (uint)cVar11;
        puVar5 = (ushort *)((int)pvVar14 + (uVar12 & 0xff) * 2);
        if ((*puVar5 & 8) != 0) break;
        if (uVar7 == uVar12) goto LAB_0059c1e8;
        if ((*puVar5 & 0x20) != 0) {
          cVar11 = param_4[2];
          uVar12 = (uint)cVar11;
          puVar5 = (ushort *)((int)pvVar14 + (uVar12 & 0xff) * 2);
          pcVar16 = param_4 + 2;
          if ((*puVar5 & 8) != 0) break;
        }
        iVar4 = iVar4 + 1;
        *(char *)(piVar3[1] + iVar4 + -1) = cVar11;
        cVar11 = pcVar16[1];
        pvVar14 = param_1->meth_data;
        param_4 = pcVar16;
      }
      if (uVar7 == uVar12) {
LAB_0059c1e8:
        uVar10 = *(ushort *)((int)pvVar14 + ((int)pcVar16[1] & 0xffU) * 2);
        uVar7 = (int)pcVar16[1];
        param_4 = pcVar16 + 1;
      }
      else {
        uVar10 = *puVar5;
        uVar7 = uVar12;
        param_4 = pcVar16;
      }
    }
    if ((uVar10 & 0x400) == 0) {
      if ((uVar10 & 0x20) == 0) {
        if ((uVar10 & 8) != 0) goto LAB_0059c394;
        if (uVar7 == 0x24) {
          uVar7 = (uint)param_4[1];
          if (uVar7 == 0x7b) {
            uVar12 = 0x7d;
            uVar7 = (uint)param_4[2];
            pcVar16 = param_4 + 2;
          }
          else {
            uVar12 = 0x29;
            if (uVar7 == 0x28) {
              uVar7 = (uint)param_4[2];
              pcVar16 = param_4 + 2;
            }
            else {
              pcVar16 = param_4 + 1;
              uVar12 = 0;
            }
          }
          uVar10 = *(ushort *)((int)pvVar14 + (uVar7 & 0xff) * 2);
          pcVar18 = pcVar16;
          while ((uVar10 & 0x107) != 0) {
            pcVar18 = pcVar18 + 1;
            uVar7 = (uint)*pcVar18;
            uVar10 = *(ushort *)((int)pvVar14 + (uVar7 & 0xff) * 2);
          }
          if ((uVar7 == 0x3a) && (pcVar18[1] == ':')) {
            uVar7 = (uint)pcVar18[2];
            pcVar13 = pcVar18 + 2;
            *pcVar18 = '\0';
            pcVar17 = pcVar13;
            if ((*(ushort *)((int)param_1->meth_data + (uVar7 & 0xff) * 2) & 0x107) != 0) {
              pcVar2 = pcVar18 + 3;
              do {
                pcVar17 = pcVar2;
                uVar7 = (uint)*pcVar17;
                pcVar2 = pcVar17 + 1;
              } while ((*(ushort *)((int)param_1->meth_data + (uVar7 & 0xff) * 2) & 0x107) != 0);
            }
            *pcVar17 = '\0';
            if (uVar12 == 0) {
              pcVar16 = _CONF_get_string(param_1,pcVar16,pcVar13);
              *pcVar18 = ':';
              pcVar13 = pcVar17;
              goto LAB_0059c314;
            }
            if (uVar12 == uVar7) {
              pcVar16 = _CONF_get_string(param_1,pcVar16,pcVar13);
              pcVar13 = pcVar17 + 1;
              *pcVar18 = ':';
              goto LAB_0059c314;
            }
LAB_0059c034:
            uVar15 = 0x66;
            uVar6 = 0x234;
          }
          else {
            *pcVar18 = '\0';
            pcVar17 = pcVar18;
            if (uVar12 == 0) {
              pcVar16 = _CONF_get_string(param_1,param_2,pcVar16);
              pcVar13 = pcVar18;
            }
            else {
              if (uVar7 != uVar12) goto LAB_0059c034;
              pcVar16 = _CONF_get_string(param_1,param_2,pcVar16);
              pcVar13 = pcVar18 + 1;
            }
LAB_0059c314:
            *pcVar17 = (char)uVar7;
            if (pcVar16 == (char *)0x0) {
              uVar15 = 0x68;
              uVar6 = 0x248;
            }
            else {
              iVar9 = (*(code *)PTR_strlen_006a9a24)(pcVar16);
              iVar9 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)
                                (piVar3,(*piVar3 - ((int)pcVar13 - (int)param_4)) + iVar9);
              if (iVar9 != 0) {
                cVar11 = *pcVar16;
                while (cVar11 != '\0') {
                  iVar4 = iVar4 + 1;
                  pcVar16 = pcVar16 + 1;
                  *(char *)(piVar3[1] + iVar4 + -1) = cVar11;
                  cVar11 = *pcVar16;
                }
                *pcVar17 = (char)uVar7;
                uVar7 = (uint)*pcVar13;
                goto LAB_0059c1d0;
              }
              uVar15 = 0x41;
              uVar6 = 0x24d;
            }
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x65,uVar15,"conf_def.c",uVar6);
          goto LAB_0059c05c;
        }
        pcVar13 = param_4 + 1;
        puVar8 = (undefined *)(piVar3[1] + iVar4);
        iVar4 = iVar4 + 1;
        *puVar8 = (char)uVar7;
        uVar7 = (uint)*pcVar13;
      }
      else {
        cVar11 = param_4[1];
        uVar7 = (uint)cVar11;
        pcVar13 = param_4 + 2;
        if ((*(ushort *)((int)pvVar14 + (uVar7 & 0xff) * 2) & 8) != 0) {
LAB_0059c394:
          *(undefined *)(piVar3[1] + iVar4) = 0;
          if (*param_3 != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          }
          puVar8 = PTR_CRYPTO_free_006a6e88;
          *param_3 = piVar3[1];
          (*(code *)puVar8)(piVar3);
          return 1;
        }
        if (uVar7 == 0x72) {
          cVar11 = '\r';
        }
        else if (uVar7 == 0x6e) {
          cVar11 = '\n';
        }
        else if (uVar7 == 0x62) {
          cVar11 = '\b';
        }
        else if (uVar7 == 0x74) {
          cVar11 = '\t';
        }
        pcVar16 = (char *)(piVar3[1] + iVar4);
        iVar4 = iVar4 + 1;
        *pcVar16 = cVar11;
        uVar7 = (uint)param_4[2];
      }
LAB_0059c1d0:
      pvVar14 = param_1->meth_data;
      uVar10 = *(ushort *)((int)pvVar14 + (uVar7 & 0xff) * 2);
      param_4 = pcVar13;
      goto LAB_0059bf2c;
    }
    uVar12 = (uint)param_4[1];
    uVar10 = *(ushort *)((int)pvVar14 + (uVar12 & 0xff) * 2);
    pcVar16 = param_4;
    while (param_4 = pcVar16 + 1, (uVar10 & 8) == 0) {
      if (uVar7 == uVar12) {
        uVar12 = (uint)pcVar16[2];
        param_4 = pcVar16 + 2;
        if (uVar7 != uVar12) goto LAB_0059c120;
      }
      iVar4 = iVar4 + 1;
      *(char *)(piVar3[1] + iVar4 + -1) = (char)uVar12;
      uVar12 = (uint)param_4[1];
      pvVar14 = param_1->meth_data;
      pcVar16 = param_4;
      uVar10 = *(ushort *)((int)pvVar14 + (uVar12 & 0xff) * 2);
    }
    bVar1 = uVar7 == uVar12;
    uVar7 = uVar12;
    if (bVar1) {
      uVar12 = (uint)pcVar16[2];
LAB_0059c120:
      uVar10 = *(ushort *)((int)pvVar14 + (uVar12 & 0xff) * 2);
      uVar7 = uVar12;
      param_4 = pcVar16 + 2;
    }
  } while( true );
}

