
/* WARNING: Restarted to delay deadcode elimination for space: register */

void gcm_ghash_neon(undefined8 *param_1,undefined4 param_2,undefined8 *param_3,int param_4)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined auVar9 [16];
  ulonglong uVar10;
  undefined auVar11 [16];
  undefined auVar12 [16];
  ulonglong uVar13;
  undefined auVar14 [16];
  undefined auVar15 [16];
  undefined uVar16;
  undefined8 uVar18;
  undefined auVar17 [16];
  
  uVar18 = SIMDExpandImmediate(0,0,0xe1);
  uVar8 = VectorShiftRight(uVar18,0x20);
  auVar11 = vrev(CONCAT88(*param_1,param_1[1]),1);
  do {
    uVar18 = *param_3;
    puVar4 = param_3 + 1;
    auVar15 = (undefined  [16])0x0;
    param_3 = param_3 + 2;
    auVar14 = (undefined  [16])0x0;
    iVar3 = 0x10;
    auVar17 = vrev(CONCAT88(uVar18,*puVar4),1);
    uVar5 = 0;
    auVar12 = (undefined  [16])0x0;
    uVar16 = SUB161(auVar17 ^ auVar11,0);
    uVar1 = CONCAT11(uVar16,uVar16);
    uVar2 = CONCAT22(uVar1,uVar1);
    uVar18 = CONCAT44(uVar2,uVar2);
    auVar11 = auVar17 ^ auVar11;
    do {
      iVar3 = iVar3 + -1;
      auVar9 = PolynomialMultiply(param_1[3],uVar18,1);
      auVar17 = PolynomialMultiply(param_1[2],uVar18,1);
      auVar12 = auVar12 ^ auVar15;
      uVar13 = VectorShiftLeft(SUB168(auVar14,0),0x30,0x40,0);
      uVar16 = SUB161(auVar11 >> 8,0);
      uVar1 = CONCAT11(uVar16,uVar16);
      uVar2 = CONCAT22(uVar1,uVar1);
      uVar18 = CONCAT44(uVar2,uVar2);
      uVar10 = SUB168(auVar12,0);
      uVar7 = SUB168(auVar9,0) ^ uVar10;
      auVar15 = VectorUnzip(auVar17,1);
      uVar6 = VectorShiftLeftInsert(uVar5,uVar7,1);
      auVar14 = PolynomialMultiply(uVar6,uVar8,1);
      uVar5 = VectorShiftRight(uVar7,7);
      auVar15 = auVar15 >> 8;
      auVar12 = CONCAT88(SUB168(auVar12 >> 0x40,0) ^ uVar13,uVar10) >> 8 ^ auVar17;
      auVar11 = auVar11 >> 8;
    } while (iVar3 != 0);
    uVar7 = VectorShiftLeft(SUB168(auVar14,0),0x30,0x40,0);
    uVar6 = SUB168(auVar12 ^ auVar15,0);
    uVar18 = VectorShiftRight(uVar6,0x3f);
    auVar11 = VectorShiftLeft(CONCAT88(SUB168((auVar12 ^ auVar15) >> 0x40,0) ^ uVar7,uVar6),1,0x40,0
                             );
    param_4 = param_4 + -0x10;
    auVar11 = auVar11 | CONCAT88(uVar18,uVar5 & uVar8);
  } while (param_4 != 0);
  auVar11 = vrev(auVar11,1);
  *param_1 = SUB168(auVar11 >> 0x40,0);
  param_1[1] = SUB168(auVar11,0);
  return;
}

