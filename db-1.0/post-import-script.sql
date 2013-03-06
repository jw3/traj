-- duplicate script, source bullet_fnf
CREATE TABLE bullet (
  id         integer PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,
  weight     float(5) NOT NULL,
  bc         float(5) NOT NULL,
  name       varchar(100) NOT NULL,
  stock      varchar(10),
  img        varchar(100),
  mfg        varchar(100) NOT NULL,
  dragfx     smallint NOT NULL DEFAULT 0,
  stdvel     integer NOT NULL,
  boundry01  float(50),
  boundry02  float(50),
  boundry03  float(50),
  boundry04  float(50),
  bc02       float(5),
  bc03       float(5),
  bc04       float(5),
  bc05       float(5),
  caliber    float(50)
);

CREATE INDEX bullet_fnf01_Index01
  ON bullet
  (id);

CREATE INDEX bullet_fnf01_Index02
  ON bullet
  (id);

CREATE INDEX bullet_fnf01_Index03
  ON bullet
  (id);

insert into bullet select * from bullet_fnf;

ALTER TABLE bullet ADD COLUMN caliber_temp integer;
ALTER TABLE bullet ADD COLUMN mfg_temp integer;
  
update bullet set mfg_temp = (select id from manufacturer where name = bullet.mfg);
update bullet set caliber_temp = (select id from caliber where caliber.caliber = bullet.caliber);

-- manually remove the mfg, caliber columns
-- manaully rename mfg_temp to mfg, caliber_temp to caliber
-- manually add fks on mfg and caliber
