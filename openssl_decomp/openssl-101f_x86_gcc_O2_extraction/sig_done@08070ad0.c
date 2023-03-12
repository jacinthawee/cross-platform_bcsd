
void sig_done(void)

{
  signal(0xe,sig_done);
  run = 0;
  return;
}

