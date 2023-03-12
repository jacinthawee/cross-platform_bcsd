
ulonglong mul_1x1_neon(void)

{
  undefined auVar1 [16];
  undefined8 uVar2;
  ulonglong uVar3;
  undefined auVar4 [16];
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined auVar8 [16];
  ulonglong uVar9;
  ulonglong uVar10;
  undefined auVar11 [16];
  ulonglong uVar12;
  undefined8 in_d16;
  undefined8 in_d17;
  
  uVar2 = VectorShiftLeft(in_d16,8,0x40,0);
  auVar1 = PolynomialMultiply(in_d16,in_d17,1);
  uVar6 = VectorShiftLeft(in_d16,0x10,0x40,0);
  auVar4 = PolynomialMultiply(uVar2,in_d17,1);
  uVar2 = VectorShiftLeft(in_d16,0x18,0x40,0);
  auVar8 = PolynomialMultiply(uVar6,in_d17,1);
  uVar3 = VectorShiftRight(SUB168(auVar4,0),8);
  auVar11 = PolynomialMultiply(uVar2,in_d17,1);
  uVar5 = VectorShiftLeft(SUB168(auVar4 >> 0x40,0),0x18,0x40,0);
  uVar7 = VectorShiftRight(SUB168(auVar8,0),0x10);
  uVar9 = VectorShiftLeft(SUB168(auVar8 >> 0x40,0),0x10,0x40,0);
  uVar10 = VectorShiftRight(SUB168(auVar11,0),0x18);
  uVar12 = VectorShiftLeft(SUB168(auVar11 >> 0x40,0),8,0x40,0);
  return SUB168(auVar1,0) ^ uVar3 ^ uVar5 ^ uVar7 ^ uVar9 ^ uVar10 ^ uVar12;
}

