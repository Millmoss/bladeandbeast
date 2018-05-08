using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InteractToken : MonoBehaviour
{
	public Camera unitCamera;
	public GameObject devDeselect;
	public GameObject devPointer;
	public GameObject devCheck;
	public Material lineMat;
	private GameObject selectedObject;
	private ArrayList movementList;
	private GameObject movementLine;
	private LineRenderer line;

	void Start ()
	{
		selectedObject = null;
		movementList = new ArrayList();
		movementLine = new GameObject();
		line = movementLine.AddComponent<LineRenderer>();
		line.startWidth = .2f;
		line.endWidth = .2f;
		line.material = lineMat;
		line.positionCount = 0;
	}
	
	void Update ()
	{
		if (Input.GetMouseButtonDown(0))
		{
			Ray ray = unitCamera.ScreenPointToRay(new Vector3(Input.mousePosition.x, Input.mousePosition.y, 0));
			LayerMask selectionMask = 1 << 8;
			RaycastHit hit = new RaycastHit();
			if (Physics.Raycast(ray, out hit, 1000f, selectionMask))
			{
				if (selectedObject == null)
				{
					selectedObject = hit.transform.gameObject;
					line.positionCount++;
					line.SetPosition(0, selectedObject.transform.position);
				}
				else
				{
					if (hit.transform.gameObject.name == "DevDeselect")
					{
						selectedObject = null;
						for (int i = 0; i < movementList.Count; i++)
							Destroy((GameObject)movementList[i]);
						movementList.Clear();
						line.positionCount = 0;
						devCheck.transform.position = new Vector3(0, -5f);
					}
					else if (hit.transform.gameObject.name.Substring(0, 4) == "Move")
					{

					}
					else if (hit.transform.gameObject.name == "DevCheck")
					{

					}
					else
						selectedObject = hit.transform.gameObject;
				}
			}
			else
			{
				if (selectedObject != null)
				{
					LayerMask levelMask = 1 << 9;
					if (Physics.Raycast(ray, out hit, 1000f, levelMask))
					{
						GameObject movementPointer = Instantiate(devPointer);
						movementPointer.name = "Move" + line.positionCount;
						movementPointer.transform.position = hit.point + new Vector3(0, 2f);
						movementList.Add(movementPointer);
						devCheck.transform.position = hit.point + new Vector3(0, 3f);
						line.positionCount++;
						line.SetPosition(line.positionCount - 1, hit.point + new Vector3(0, .1f));
					}
				}
			}
		}

		if (selectedObject != null)
		{
			devDeselect.transform.position = selectedObject.transform.position + new Vector3(0, 2f);
		}
		else
		{
			devDeselect.transform.position = new Vector3(0, -5f);
		}
	}
}
