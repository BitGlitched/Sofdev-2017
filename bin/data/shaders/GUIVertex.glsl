#version 330 core

layout (location = 0) in vec2 vertCoord;
layout (location = 1) in vec2 texCoord;

out vec4 fragColor;
out vec2 TexCoord;

uniform int texMode;

uniform float aspect;

uniform vec2 position;
uniform vec2 scale;
uniform vec2 imageSize;
uniform vec2 windowSize;
uniform vec2 uvScale;
uniform vec2 uvOffset;

uniform vec4 tint;

void main()
{
   //Position calculation section
   /*float xCoord = vertCoord.x * imageAspect.x * uvScale.x * scale.x;
   float yCoord = vertCoord.y * imageAspect.y * uvScale.y * scale.y * aspect;

   float xPosition = xCoord - 1.0f + (position.x / windowSize.x);
   float yPosition = yCoord + 1.0f - (position.y / windowSize.y * aspect);

   gl_Position = vec4(xPosition, yPosition, 0, 1.0f);*/
   float xCoord = ((vertCoord.x * imageSize.x * scale.x) / 1280) + (position.x / 640);
   float yCoord = ((vertCoord.y * imageSize.y * scale.y) / 720) + (position.y / 360);

   gl_Position = vec4(xCoord, yCoord, 0, 1.0f);

   fragColor = tint;
   TexCoord = ((texCoord) + (uvOffset));

   if (texMode == 1)
   {
      TexCoord *= scale;
   }
}
