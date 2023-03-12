
/* WARNING: Restarted to delay deadcode elimination for space: register */

void gcm_gmult_neon(undefined8 *param_1,int param_2,undefined8 *param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 *puVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined auVar11 [16];
  undefined auVar12 [16];
  ulonglong uVar13;
  undefined auVar14 [16];
  ulonglong uVar15;
  undefined auVar16 [16];
  undefined auVar17 [16];
  undefined uVar18;
  undefined auVar19 [16];
  
  uVar9 = SIMDExpandImmediate(0,0,0xe1);
  uVar10 = VectorShiftRight(uVar9,0x20);
  auVar19 = vrev(CONCAT88(*param_1,param_1[1]),1);
  auVar17 = (undefined  [16])0x0;
  auVar16 = (undefined  [16])0x0;
  iVar3 = 0x10;
  auVar14 = (undefined  [16])0x0;
  iVar5 = 0x10;
  uVar6 = 0;
  uVar1 = CONCAT11(SUB161(auVar19,0),SUB161(auVar19,0));
  uVar2 = CONCAT22(uVar1,uVar1);
  uVar9 = CONCAT44(uVar2,uVar2);
  while( true ) {
    do {
      iVar3 = iVar3 + -1;
      auVar12 = PolynomialMultiply(*(undefined8 *)(param_2 + -8),uVar9,1);
      auVar11 = PolynomialMultiply(*(undefined8 *)(param_2 + -0x10),uVar9,1);
      auVar14 = auVar14 ^ auVar17;
      uVar15 = VectorShiftLeft(SUB168(auVar16,0),0x30,0x40,0);
      uVar18 = SUB161(auVar19 >> 8,0);
      uVar1 = CONCAT11(uVar18,uVar18);
      uVar2 = CONCAT22(uVar1,uVar1);
      uVar9 = CONCAT44(uVar2,uVar2);
      uVar13 = SUB168(auVar14,0);
      uVar8 = SUB168(auVar12,0) ^ uVar13;
      auVar17 = VectorUnzip(auVar11,1);
      uVar7 = VectorShiftLeftInsert(uVar6,uVar8,1);
      auVar16 = PolynomialMultiply(uVar7,uVar10,1);
      uVar6 = VectorShiftRight(uVar8,7);
      auVar17 = auVar17 >> 8;
      auVar14 = CONCAT88(SUB168(auVar14 >> 0x40,0) ^ uVar15,uVar13) >> 8 ^ auVar11;
      auVar19 = auVar19 >> 8;
    } while (iVar3 != 0);
    uVar8 = VectorShiftLeft(SUB168(auVar16,0),0x30,0x40,0);
    uVar7 = SUB168(auVar14 ^ auVar17,0);
    uVar9 = VectorShiftRight(uVar7,0x3f);
    auVar14 = VectorShiftLeft(CONCAT88(SUB168((auVar14 ^ auVar17) >> 0x40,0) ^ uVar8,uVar7),1,0x40,0
                             );
    iVar5 = iVar5 + -0x10;
    auVar14 = auVar14 | CONCAT88(uVar9,uVar6 & uVar10);
    if (iVar5 == 0) break;
    uVar9 = *param_3;
    puVar4 = param_3 + 1;
    auVar17 = (undefined  [16])0x0;
    param_3 = param_3 + 2;
    auVar16 = (undefined  [16])0x0;
    iVar3 = 0x10;
    auVar19 = vrev(CONCAT88(uVar9,*puVar4),1);
    uVar6 = 0;
    auVar19 = auVar19 ^ auVar14;
    auVar14 = (undefined  [16])0x0;
    uVar1 = CONCAT11(SUB161(auVar19,0),SUB161(auVar19,0));
    uVar2 = CONCAT22(uVar1,uVar1);
    uVar9 = CONCAT44(uVar2,uVar2);
  }
  auVar17 = vrev(auVar14,1);
  *param_1 = SUB168(auVar17 >> 0x40,0);
  param_1[1] = SUB168(auVar17,0);
  return;
}

