/*
 Copyright © 2021  TokiNoBug
This file is part of SlopeCraft.

    SlopeCraft is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SlopeCraft is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SlopeCraft.  If not, see <https://www.gnu.org/licenses/>.
    
    Contact with me:
    github:https://github.com/ToKiNoBug
    bilibili:https://space.bilibili.com/351429231
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"

#include  <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#ifndef Collecter_H
#define Collecter_H

void MainWindow::Collect()
{
    for(short Base=0;Base<64;Base++)
    {Enables[Base]=NULL;
        ShowColors[Base]=NULL;
        for(short j=0;j<9;j++)
        {
            Blocks[Base][j]=NULL;
            Data.BlockId[Base][j]="DefaultBlockId";
            Data.BlockVersion[Base][j]=0;//0代表很早以前就出现的方块，255代表没有对应的方块
        }

    }

    //////////////
    Enables[0]=ui->Enable00;
    Enables[1]=ui->Enable01;
    Enables[2]=ui->Enable02;
    Enables[3]=ui->Enable03;
    Enables[4]=ui->Enable04;
    Enables[5]=ui->Enable05;
    Enables[6]=ui->Enable06;
    Enables[7]=ui->Enable07;
    Enables[8]=ui->Enable08;
    Enables[9]=ui->Enable09;
    Enables[10]=ui->Enable10;
    Enables[11]=ui->Enable11;
    Enables[12]=ui->Enable12;
    Enables[13]=ui->Enable13;
    Enables[14]=ui->Enable14;
    Enables[15]=ui->Enable15;
    Enables[16]=ui->Enable16;
    Enables[17]=ui->Enable17;
    Enables[18]=ui->Enable18;
    Enables[19]=ui->Enable19;
    Enables[20]=ui->Enable20;
    Enables[21]=ui->Enable21;
    Enables[22]=ui->Enable22;
    Enables[23]=ui->Enable23;
    Enables[24]=ui->Enable24;
    Enables[25]=ui->Enable25;
    Enables[26]=ui->Enable26;
    Enables[27]=ui->Enable27;
    Enables[28]=ui->Enable28;
    Enables[29]=ui->Enable29;
    Enables[30]=ui->Enable30;
    Enables[31]=ui->Enable31;
    Enables[32]=ui->Enable32;
    Enables[33]=ui->Enable33;
    Enables[34]=ui->Enable34;
    Enables[35]=ui->Enable35;
    Enables[36]=ui->Enable36;
    Enables[37]=ui->Enable37;
    Enables[38]=ui->Enable38;
    Enables[39]=ui->Enable39;
    Enables[40]=ui->Enable40;
    Enables[41]=ui->Enable41;
    Enables[42]=ui->Enable42;
    Enables[43]=ui->Enable43;
    Enables[44]=ui->Enable44;
    Enables[45]=ui->Enable45;
    Enables[46]=ui->Enable46;
    Enables[47]=ui->Enable47;
    Enables[48]=ui->Enable48;
    Enables[49]=ui->Enable49;
    Enables[50]=ui->Enable50;
    Enables[51]=ui->Enable51;
    Enables[52]=ui->Enable52;
    Enables[53]=ui->Enable53;
    Enables[54]=ui->Enable54;
    Enables[55]=ui->Enable55;
    Enables[56]=ui->Enable56;
    Enables[57]=ui->Enable57;
    Enables[58]=ui->Enable58;
    /////////////////
    ShowColors[0]=ui->Color00;
    ShowColors[1]=ui->Color01;
    ShowColors[2]=ui->Color02;
    ShowColors[3]=ui->Color03;
    ShowColors[4]=ui->Color04;
    ShowColors[5]=ui->Color05;
    ShowColors[6]=ui->Color06;
    ShowColors[7]=ui->Color07;
    ShowColors[8]=ui->Color08;
    ShowColors[9]=ui->Color09;
    ShowColors[10]=ui->Color10;
    ShowColors[11]=ui->Color11;
    ShowColors[12]=ui->Color12;
    ShowColors[13]=ui->Color13;
    ShowColors[14]=ui->Color14;
    ShowColors[15]=ui->Color15;
    ShowColors[16]=ui->Color16;
    ShowColors[17]=ui->Color17;
    ShowColors[18]=ui->Color18;
    ShowColors[19]=ui->Color19;
    ShowColors[20]=ui->Color20;
    ShowColors[21]=ui->Color21;
    ShowColors[22]=ui->Color22;
    ShowColors[23]=ui->Color23;
    ShowColors[24]=ui->Color24;
    ShowColors[25]=ui->Color25;
    ShowColors[26]=ui->Color26;
    ShowColors[27]=ui->Color27;
    ShowColors[28]=ui->Color28;
    ShowColors[29]=ui->Color29;
    ShowColors[30]=ui->Color30;
    ShowColors[31]=ui->Color31;
    ShowColors[32]=ui->Color32;
    ShowColors[33]=ui->Color33;
    ShowColors[34]=ui->Color34;
    ShowColors[35]=ui->Color35;
    ShowColors[36]=ui->Color36;
    ShowColors[37]=ui->Color37;
    ShowColors[38]=ui->Color38;
    ShowColors[39]=ui->Color39;
    ShowColors[40]=ui->Color40;
    ShowColors[41]=ui->Color41;
    ShowColors[42]=ui->Color42;
    ShowColors[43]=ui->Color43;
    ShowColors[44]=ui->Color44;
    ShowColors[45]=ui->Color45;
    ShowColors[46]=ui->Color46;
    ShowColors[47]=ui->Color47;
    ShowColors[48]=ui->Color48;
    ShowColors[49]=ui->Color49;
    ShowColors[50]=ui->Color50;
    ShowColors[51]=ui->Color51;
    ShowColors[52]=ui->Color52;
    ShowColors[53]=ui->Color53;
    ShowColors[54]=ui->Color54;
    ShowColors[55]=ui->Color55;
    ShowColors[56]=ui->Color56;
    ShowColors[57]=ui->Color57;
    ShowColors[58]=ui->Color58;
    ////////////////
    Blocks[0][0]=ui->is00Glass;     Data.BlockId[0][0]="glass";

    Blocks[1][0]=ui->is01Grass;     Data.BlockId[1][0]="grass_block[snowy=false]";
    Blocks[1][1]=ui->is01SlimeBlock;        Data.BlockId[1][1]="slime_block";

    Blocks[2][0]=ui->is02BirchPlanks;       Data.BlockId[2][0]="birch_planks";
    Blocks[2][1]=ui->is02SmoothSandstone;       Data.BlockId[2][1]="smooth_sandstone";
    Blocks[2][2]=ui->is02Glowstone;       Data.BlockId[2][2]="glowstone";
    Blocks[2][3]=ui->is02EndStone;       Data.BlockId[2][3]="end_stone";
    Blocks[2][4]=ui->is02EndBricks;       Data.BlockId[2][4]="end_stone_bricks";
    Blocks[2][5]=ui->is02TurtleEgg;       Data.BlockId[2][5]="turtle_egg[eggs=4,hatch=0]";Data.BlockVersion[2][5]=13;

    Blocks[3][0]=ui->is03MushroomStem;       Data.BlockId[3][0]="mushroom_stem[east=true,west=true,north=true,south=true,up=true,down=true]";
    Blocks[3][1]=ui->is03CobWeb;       Data.BlockId[3][1]="cobweb";

    Blocks[4][0]=ui->is04RedstoneBlock;       Data.BlockId[4][0]="redstone_block";
    Blocks[4][1]=ui->is04TNT;       Data.BlockId[4][1]="tnt[unstable=false]";

    Blocks[5][0]=ui->is05Ice;       Data.BlockId[5][0]="ice";
    Blocks[5][1]=ui->is05PackedIce;       Data.BlockId[5][1]="packed_ice";
    Blocks[5][2]=ui->is05BlueIce;       Data.BlockId[5][2]="blue_ice";

    Blocks[6][0]=ui->is06IronBlock;       Data.BlockId[6][0]="iron_block";
    Blocks[6][1]=ui->is06BrewingStand;       Data.BlockId[6][1]="brewing_stand[has_bottle_0=false,has_bottle_1=false,has_bottle_2=false]";
    Blocks[6][2]=ui->is06IronPlate;       Data.BlockId[6][2]="heavy_weighted_pressure_plate[power=0]";
    Blocks[6][3]=ui->is06IronTrapDoor;       Data.BlockId[6][3]="iron_trapdoor[facing=north,half=top,open=false,powered=false,waterlogged=false]";
    Blocks[6][4]=ui->is06Lantern;       Data.BlockId[6][4]="lantern[hanging=false]";Data.BlockVersion[6][4]=14;
    Blocks[6][5]=ui->is06Grindstone;       Data.BlockId[6][5]="grindstone[face=floor,facing=north]";Data.BlockVersion[6][5]=14;

    Blocks[7][0]=ui->is07OakLeaves;       Data.BlockId[7][0]="oak_leaves[distance=7,persistent=true]";
    Blocks[7][1]=ui->is07SpruceLeaves;       Data.BlockId[7][1]="spruce_leaves[distance=7,persistent=true]";
    Blocks[7][2]=ui->is07BirchLeaves;       Data.BlockId[7][2]="birch_leaves[distance=7,persistent=true]";
    Blocks[7][3]=ui->is07JungleLeaves;       Data.BlockId[7][3]="jungle_leaves[distance=7,persistent=true]";
    Blocks[7][4]=ui->is07AcaciaLeaves;       Data.BlockId[7][4]="acacia_leaves[distance=7,persistent=true]";
    Blocks[7][5]=ui->is07DarkOakLeaves;       Data.BlockId[7][5]="dark_oak_leaves[distance=7,persistent=true]";

    Blocks[8][0]=ui->is08Concrete;       Data.BlockId[8][0]="white_concrete";
    Blocks[8][1]=ui->is08Wool;       Data.BlockId[8][1]="white_wool";
    Blocks[8][2]=ui->is08StainedGlass;       Data.BlockId[8][2]="white_stained_glass";
    Blocks[8][3]=ui->is08SnowBlock;       Data.BlockId[8][3]="snow_block";

    Blocks[9][0]=ui->is09Clay;      Data.BlockId[9][0]="clay";

    Blocks[10][0]=ui->is10CoarseDirt;      Data.BlockId[10][0]="coarse_dirt";Data.BlockVersion[10][0]=13;
    Blocks[10][1]=ui->is10PolishedGranite;      Data.BlockId[10][1]="polished_granite";
    Blocks[10][2]=ui->is10JunglePlanks;      Data.BlockId[10][2]="jungle_planks";
    Blocks[10][3]=ui->is10BrownMushroomBlock;      Data.BlockId[10][3]="brown_mushroom_block[east=true,west=true,north=true,south=true,up=true,down=true]";
    Blocks[10][4]=ui->is10Dirt;      Data.BlockId[10][4]="dirt";

    Blocks[11][0]=ui->is11Cobblestone;      Data.BlockId[11][0]="cobblestone";
    Blocks[11][1]=ui->is11Stone;      Data.BlockId[11][1]="stone";
    Blocks[11][2]=ui->is11SmoothStone;      Data.BlockId[11][2]="smooth_stone";
    Blocks[11][3]=ui->is11StoneBricks;      Data.BlockId[11][3]="stone_bricks";

    Blocks[12][0]=ui->is12Water;      Data.BlockId[12][0]="water[level=0]";

    Blocks[13][0]=ui->is13OakPlanks;      Data.BlockId[13][0]="oak_planks";

    Blocks[14][0]=ui->is14PolishedDiorite;      Data.BlockId[14][0]="polished_diorite";
    Blocks[14][1]=ui->is14QuartzBlock;      Data.BlockId[14][1]="quartz_block";
    Blocks[14][2]=ui->is14SeaLantern;      Data.BlockId[14][2]="sea_lantern";
    Blocks[14][3]=ui->is14Target;      Data.BlockId[14][3]="target[power=0]";Data.BlockVersion[14][3]=16;

    Blocks[15][0]=ui->is15Concrete;      Data.BlockId[15][0]="orange_concrete";
    Blocks[15][1]=ui->is15Wool;      Data.BlockId[15][1]="orange_wool";
    Blocks[15][2]=ui->is15StainedGlass;      Data.BlockId[15][2]="orange_stained_glass";
    Blocks[15][3]=ui->is15AcaciaPlanks;      Data.BlockId[15][3]="acacia_planks";
    Blocks[15][4]=ui->is15Pumpkin;      Data.BlockId[15][4]="pumpkin";
    Blocks[15][5]=ui->is15Terracotta;      Data.BlockId[15][5]="terracotta";
    Blocks[15][6]=ui->is15SmoothRedsandstone;      Data.BlockId[15][6]="smooth_red_sandstone";
    Blocks[15][7]=ui->is15HoneyBlock;      Data.BlockId[15][7]="honey_block";Data.BlockVersion[15][7]=15;
    Blocks[15][8]=ui->is15Honeycomb;      Data.BlockId[15][8]="honeycomb_block";Data.BlockVersion[15][8]=15;

    Blocks[16][0]=ui->is16Concrete;      Data.BlockId[16][0]="magenta_concrete";
    Blocks[16][1]=ui->is16Wool;      Data.BlockId[16][1]="magenta_wool";
    Blocks[16][2]=ui->is16StainedGlass;      Data.BlockId[16][2]="magenta_stained_glass";
    Blocks[16][3]=ui->is16PurpurBlock;      Data.BlockId[16][3]="purpur_block";

    Blocks[17][0]=ui->is17Concrete;      Data.BlockId[17][0]="light_blue_concrete";
    Blocks[17][1]=ui->is17Wool;      Data.BlockId[17][1]="light_blue_wool";
    Blocks[17][2]=ui->is17StainedGlass;      Data.BlockId[17][2]="light_blue_stained_glass";

    Blocks[18][0]=ui->is18Concrete;      Data.BlockId[18][0]="yellow_concrete";
    Blocks[18][1]=ui->is18Wool;      Data.BlockId[18][1]="yellow_wool";
    Blocks[18][2]=ui->is18StainedGlass;      Data.BlockId[18][2]="yellow_stained_glass";
    Blocks[18][3]=ui->is18HayBlock;      Data.BlockId[18][3]="hay_block[axis=y]";

    Blocks[19][0]=ui->is19Concrete;      Data.BlockId[19][0]="lime_concrete";
    Blocks[19][1]=ui->is19Wool;      Data.BlockId[19][1]="lime_wool";
    Blocks[19][2]=ui->is19StainedGlass;      Data.BlockId[19][2]="lime_stained_glass";

    Blocks[20][0]=ui->is20Concrete;      Data.BlockId[20][0]="pink_concrete";
    Blocks[20][1]=ui->is20Wool;      Data.BlockId[20][1]="pink_wool";
    Blocks[20][2]=ui->is20StainedGlass;      Data.BlockId[20][2]="pink_stained_glass";

    Blocks[21][0]=ui->is21Concrete;      Data.BlockId[21][0]="gray_concrete";
    Blocks[21][1]=ui->is21Wool;      Data.BlockId[21][1]="gray_wool";
    Blocks[21][2]=ui->is21StainedGlass;      Data.BlockId[21][2]="gray_stained_glass";

    Blocks[22][0]=ui->is22Concrete;      Data.BlockId[22][0]="light_gray_concrete";
    Blocks[22][1]=ui->is22Wool;      Data.BlockId[22][1]="light_gray_wool";
    Blocks[22][2]=ui->is22StainedGlass;      Data.BlockId[22][2]="light_gray_stained_glass";

    Blocks[23][0]=ui->is23Concrete;      Data.BlockId[23][0]="cyan_concrete";
    Blocks[23][1]=ui->is23Wool;      Data.BlockId[23][1]="cyan_wool";
    Blocks[23][2]=ui->is23StainedGlass;      Data.BlockId[23][2]="cyan_stained_glass";
    Blocks[23][3]=ui->is23Prismarine;      Data.BlockId[23][3]="prismarine";//Data.BlockVersion[23][3]=13;

    Blocks[24][0]=ui->is24Concrete;      Data.BlockId[24][0]="purple_concrete";
    Blocks[24][1]=ui->is24Wool;      Data.BlockId[24][1]="light_blue_wool";
    Blocks[24][2]=ui->is24StainedGlass;      Data.BlockId[24][2]="light_blue_stained_glass";

    Blocks[25][0]=ui->is25Concrete;      Data.BlockId[25][0]="blue_concrete";
    Blocks[25][1]=ui->is25Wool;      Data.BlockId[25][1]="blue_wool";
    Blocks[25][2]=ui->is25StainedGlass;      Data.BlockId[25][2]="blue_stained_glass";

    Blocks[26][0]=ui->is26Concrete;      Data.BlockId[26][0]="brown_concrete";
    Blocks[26][1]=ui->is26Wool;      Data.BlockId[26][1]="brown_wool";
    Blocks[26][2]=ui->is26StainedGlass;      Data.BlockId[26][2]="brown_stained_glass";
    Blocks[26][3]=ui->is26DarkOakPlanks;      Data.BlockId[26][3]="dark_oak_planks";
    Blocks[26][4]=ui->is26SoulSand;      Data.BlockId[26][4]="soul_sand";
    Blocks[26][5]=ui->is26SoulSoil;      Data.BlockId[26][5]="soul_soil";Data.BlockVersion[26][5]=16;

    Blocks[27][0]=ui->is27Concrete;      Data.BlockId[27][0]="green_concrete";
    Blocks[27][1]=ui->is27Wool;      Data.BlockId[27][1]="green_wool";
    Blocks[27][2]=ui->is27StainedGlass;      Data.BlockId[27][2]="green_stained_glass";
    Blocks[27][3]=ui->is27KelpBlock;      Data.BlockId[27][3]="dried_kelp_block";Data.BlockVersion[27][3]=13;

    Blocks[28][0]=ui->is28Concrete;      Data.BlockId[28][0]="red_concrete";
    Blocks[28][1]=ui->is28Wool;      Data.BlockId[28][1]="red_wool";
    Blocks[28][2]=ui->is28StainedGlass;      Data.BlockId[28][2]="red_stained_glass";
    Blocks[28][3]=ui->is28Bricks;      Data.BlockId[28][3]="bricks";
    Blocks[28][4]=ui->is28RedMushroomBlock;      Data.BlockId[28][4]="red_mushroom_block[east=true,west=true,north=true,south=true,up=true,down=true]";
    Blocks[28][5]=ui->is28WartBlock;      Data.BlockId[28][5]="nether_wart_block";
    Blocks[28][6]=ui->is28Shroomlight;      Data.BlockId[28][6]="shroomlight";Data.BlockVersion[28][6]=16;

    Blocks[29][0]=ui->is29Concrete;      Data.BlockId[29][0]="black_concrete";
    Blocks[29][1]=ui->is29Wool;      Data.BlockId[29][1]="black_wool";
    Blocks[29][2]=ui->is29StainedGlass;      Data.BlockId[29][2]="black_stained_glass";
    Blocks[29][3]=ui->is29Obsidian;      Data.BlockId[29][3]="obsidian";
    Blocks[29][4]=ui->is29CoalBlock;      Data.BlockId[29][4]="coal_block";
    Blocks[29][5]=ui->is29Basalt;      Data.BlockId[29][5]="polished_basalt[axis=y]";Data.BlockVersion[29][5]=16;
    Blocks[29][6]=ui->is29BlackStone;      Data.BlockId[29][6]="polished_blackstone";Data.BlockVersion[29][6]=16;

    Blocks[30][0]=ui->is30GoldBlock;      Data.BlockId[30][0]="gold_block";
    Blocks[30][1]=ui->is30GoldPlate;      Data.BlockId[30][1]="light_weighted_pressure_plate[power=0]";

    Blocks[31][0]=ui->is31DiamondBlock;      Data.BlockId[31][0]="diamond_block";
    Blocks[31][1]=ui->is31PrismarineBricks;      Data.BlockId[31][1]="prismarine_bricks";//Data.BlockVersion[31][1]=13;
    Blocks[31][2]=ui->is31DarkPrismarine;      Data.BlockId[31][2]="dark_prismarine";//Data.BlockVersion[31][2]=13;

    Blocks[32][0]=ui->is32LapisBlock;      Data.BlockId[32][0]="lapis_block";

    Blocks[33][0]=ui->is33EmeraldBlock;         Data.BlockId[33][0]="emerald_block";

    Blocks[34][0]=ui->is34Podzol;         Data.BlockId[34][0]="podzol[snowy=false]";
    Blocks[34][1]=ui->is34SprucePlanks;         Data.BlockId[34][1]="spruce_planks";
    Blocks[34][2]=ui->is34Campfire;         Data.BlockId[34][2]="campfire[facing=north,lit=true,signal_fire=false,waterlogged=false]";Data.BlockVersion[34][2]=14;

    Blocks[35][0]=ui->is35Netherrack;         Data.BlockId[35][0]="netherrack";
    Blocks[35][1]=ui->is35NetherBricks;         Data.BlockId[35][1]="nether_bricks";
    Blocks[35][2]=ui->is35Magma;         Data.BlockId[35][2]="magma_block";

    Blocks[36][0]=ui->is36Terracotta;           Data.BlockId[36][0]="white_terracotta";
    Blocks[37][0]=ui->is37Terracotta;           Data.BlockId[37][0]="orange_terracotta";
    Blocks[38][0]=ui->is38Terracotta;           Data.BlockId[38][0]="magenta_terracotta";
    Blocks[39][0]=ui->is39Terracotta;           Data.BlockId[39][0]="light_blue_terracotta";
    Blocks[40][0]=ui->is40Terracotta;           Data.BlockId[40][0]="yellow_terracotta";
    Blocks[41][0]=ui->is41Terracotta;           Data.BlockId[41][0]="lime_terracotta";
    Blocks[42][0]=ui->is42Terracotta;           Data.BlockId[42][0]="pink_terracotta";
    Blocks[43][0]=ui->is43Terracotta;           Data.BlockId[43][0]="gray_terracotta";
    Blocks[44][0]=ui->is44Terracotta;           Data.BlockId[44][0]="light_gray_terracotta";
    Blocks[45][0]=ui->is45Terracotta;           Data.BlockId[45][0]="cyan_terracotta";
    Blocks[46][0]=ui->is46Terracotta;           Data.BlockId[46][0]="purple_terracotta";
    Blocks[47][0]=ui->is47Terracotta;           Data.BlockId[47][0]="blue_terracotta";
    Blocks[48][0]=ui->is48Terracotta;           Data.BlockId[48][0]="brown_terracotta";
    Blocks[49][0]=ui->is49Terracotta;           Data.BlockId[49][0]="green_terracotta";
    Blocks[50][0]=ui->is50Terracotta;           Data.BlockId[50][0]="red_terracotta";
    Blocks[51][0]=ui->is51Terracotta;           Data.BlockId[51][0]="black_terracotta";

    Blocks[52][0]=ui->is52CrimsonNylium;           Data.BlockId[52][0]="crimson_nylium";Data.BlockVersion[52][0]=16;

    Blocks[53][0]=ui->is53CrimsonPlanks;           Data.BlockId[53][0]="crimson_planks";Data.BlockVersion[53][0]=16;
    Blocks[53][1]=ui->is53StrippedCrimsonLog;           Data.BlockId[53][1]="stripped_crimson_stem[axis=y]";Data.BlockVersion[53][1]=16;

    Blocks[54][0]=ui->is54CrimsonStem;           Data.BlockId[54][0]="crimson_hyphae[axis=y]";Data.BlockVersion[54][0]=16;
    Blocks[54][1]=ui->is54StrippedCrimsonStem;           Data.BlockId[54][1]="stripped_crimson_hyphae[axis=y]";Data.BlockVersion[54][1]=16;

    Blocks[55][0]=ui->is55WarpedNylium;           Data.BlockId[55][0]="warped_nylium";Data.BlockVersion[55][0]=16;

    Blocks[56][0]=ui->is56WarpedPlanks;           Data.BlockId[56][0]="warped_planks";Data.BlockVersion[56][0]=16;
    Blocks[56][1]=ui->is56StrippedWarpedLog;           Data.BlockId[56][1]="stripped_warped_stem[axis=y]";Data.BlockVersion[56][1]=16;

    Blocks[57][0]=ui->is57WarpedStem;           Data.BlockId[57][0]="warped_hyphae[axis=y]";Data.BlockVersion[57][0]=16;
    Blocks[57][1]=ui->is57StrippedWarpedStem;           Data.BlockId[57][1]="stripped_warped_hyphae[axis=y]";Data.BlockVersion[57][1]=16;

    Blocks[58][0]=ui->is58WarpedWartBlock;           Data.BlockId[58][0]="warped_wart_block";Data.BlockVersion[58][0]=16;

    for(short r=0;r<64;r++)
        for(short c=0;c<9;c++)
            if(Blocks[r][c]==NULL)Data.BlockVersion[r][c]=255;

}


#endif
